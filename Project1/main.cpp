// main.cpp : Ce fichier contient la fonction 'main'. Elle sert a lancer l'heuristique du problème.

#include "CException.h"
#include "CCommande.h"
#include "Algo.cpp"
#include <iostream>
#include <ranges>
#include <regex>
#include <chrono>
#include <cmath>

using namespace std;
using json = nlohmann::json;

constexpr auto PasDeFichierEnArgument = 1;
constexpr auto TropDArguments = 2;
constexpr auto FichierInvalide = 3;

/// <summary>
/// Fait la fonction split de python.
/// </summary>
/// <param name="str">La chaîne de caractère a split </param>
/// <param name="regex_str">Le caractère ou chaîne qui définit le split.</param>
/// <returns>La chaîne de caractère splitté.</returns>
static std::vector<std::string> split(const std::string str,
	const std::string regex_str) {
	std::regex regexz(regex_str);
	return { std::sregex_token_iterator(str.begin(), str.end(), regexz, -1),
			std::sregex_token_iterator() };
};

/// <summary>
/// Transforme une liste de colis placée en tableau JSON.
/// </summary>
/// <param name="listeColisPlaced"></param>
/// <returns></returns>
static json ExportListeColisPlaced(const std::vector<CColisPlaced>& listeColisPlaced) {
	json jsonArray = json::array();
	for (const auto& colisPlaced : listeColisPlaced) {
		jsonArray.push_back(colisPlaced.ToJSON());
	}
	return jsonArray;
}

/// <summary>
/// Fonction lançant l'algorithme de bin-packing.
/// </summary>
/// <param name="argc">Le nombre de paramètre</param>
/// <param name="argv">Le tableau de paramètre</param>
/// <returns></returns>
int main(int argc, char* argv[])
{
	//On récupère les exceptions.
	try 
	{
		//On regarde s'il y'a bien deux arguments (Le nom du fichier et l'algorithme)
		if (argc == 1 || argc > 2)
		{
			if (argc == 1)
			{
				CException EXCErreur;
				EXCErreur.EXCModifierValeur(PasDeFichierEnArgument);
				throw EXCErreur;
			}
			if (argc > 2)
			{
				CException EXCErreur;
				EXCErreur.EXCModifierValeur(TropDArguments);
				throw EXCErreur;
			}
		}
		else
		{
			//Parsing du fichier d'entrée.
			cout << "Lecture du fichier d'entrée" << endl;
			ifstream fichier(argv[1]);
			vector<CCommande> ListeDeCommande;
			vector<CColis> ListeDeColis;
			unsigned int LongueurCamion=0;
			unsigned int LargeurCamion=0;
			if (fichier)
			{
				string ligne;
				int count = 0;

				while (getline(fichier, ligne)) 
				{
					if (count == 0) 
					{
						if (ligne.rfind("!",0) != 0) 
						{
							CException EXCErreur;
							EXCErreur.EXCModifierValeur(PasDeFichierEnArgument);
							throw EXCErreur;
						}
						else 
						{
							auto tokens = split(ligne, ",");
							if (tokens.size() != 6) 
							{
								CException EXCErreur;
								EXCErreur.EXCModifierValeur(FichierInvalide);
								throw EXCErreur;
							}
							LargeurCamion = static_cast<unsigned int>(stoul(tokens[1]));
							LongueurCamion = static_cast<unsigned int>(stoul(tokens[2]));

						}
					}
					else
					{
						if (count == 1)
						{
							if (!ligne.rfind("*", 0) == 0)
							{
								CException EXCErreur;
								EXCErreur.EXCModifierValeur(FichierInvalide);
								throw EXCErreur;
							}
							
						}
						if (ligne.rfind("*", 0) == 0)
						{
							auto tokens = split(ligne, ",");
							if (tokens.size() != 6)
							{
								CException EXCErreur;
								EXCErreur.EXCModifierValeur(FichierInvalide);
								throw EXCErreur;
							}
							else
							{
								if(ListeDeCommande.size() != 0)
								{
									if(ListeDeColis.size() == 0)
									{
										CException EXCErreur;
										EXCErreur.EXCModifierValeur(FichierInvalide);
										throw EXCErreur;
									}
									ListeDeCommande[ListeDeCommande.size() - 1].COMModifierListeColis(ListeDeColis);
								}
								unsigned int uiNumeroCommande = static_cast<unsigned int>(std::stoul(tokens[1]));
								string NomClient = tokens[2];
								CCommande NouvelleCommande(uiNumeroCommande, NomClient);
								ListeDeCommande.push_back(NouvelleCommande);
								cout << ListeDeCommande[0].COMLireNumeroCommande() << endl;
								ListeDeColis.clear();
							}
						}
						else 
						{
							auto tokens = split(ligne, ",");
							if (tokens.size() != 7)
							{
								CException EXCErreur;
								EXCErreur.EXCModifierValeur(FichierInvalide);
								throw EXCErreur;
							}
							unsigned int uiLargeur = static_cast<unsigned int>(std::stoul(tokens[0]));
							unsigned int uiLongueur = static_cast<unsigned int>(std::stoul(tokens[1]));
							unsigned int uiHauteur = static_cast<unsigned int>(std::stoul(tokens[2]));
							unsigned int uiPoids = static_cast<unsigned int>(std::stoul(tokens[3]));
							unsigned int uiNbColis = static_cast<unsigned int>(std::stoul(tokens[4]));
							unsigned int uiNumCommande = ListeDeCommande[ListeDeCommande.size() - 1].COMLireNumeroCommande();
							CColis NouveauColis(uiLongueur, uiLargeur, uiHauteur, uiPoids,uiNumCommande,uiNbColis);
							ListeDeColis.push_back(NouveauColis);
						}
					}
					count++;
				}
				if (ListeDeColis.size() == 0)
				{
						CException EXCErreur;
						EXCErreur.EXCModifierValeur(FichierInvalide);
						throw EXCErreur;
				}
				ListeDeCommande[ListeDeCommande.size() - 1].COMModifierListeColis(ListeDeColis);
			}
			for (auto const& i : ListeDeCommande) 
			{
				cout << "Le numéro de commande est " << i.COMLireNumeroCommande() << " et la liste d'objet est : " << endl;
				cout << i.COMLireListeColis().size() << endl;
				for (auto const& k : i.COMLireListeColis())
				{
					cout << "Largeur : " << k.COLLireLargeur() << ", Longueur: " << k.COLLireLongueur() << ", Hauteur: " << k.COLLireHauteur() << ", Poids: " << k.COLLirePoids() << ", NBColis: " << k.COLLireNbColis() << endl;

				}
			}
			chrono::system_clock::time_point start = std::chrono::system_clock::now();
			vector<CColisPlaced> ListeDesColisPlacee = Algorithme(ListeDeCommande, LongueurCamion, LargeurCamion);
			std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
			std::cout << "took " << sec.count() << " seconds\n";

			json ListeJson = ExportListeColisPlaced(ListeDesColisPlacee);
			json JsonArray;

			JsonArray["largeurCamion"] = LargeurCamion;
			JsonArray["longueurCamion"] = LongueurCamion;
			JsonArray["colis"] = ListeJson;

			ofstream fichierJson("listeColisPlaced.json");
			fichierJson << JsonArray.dump(4).c_str();
			fichierJson.close();
			fichier.close();
		}
	}
	catch (CException EXCErreur)
	{
		if (EXCErreur.EXCLireValeur() == PasDeFichierEnArgument) cout << "ERREUR : Pas de nom de fichier spécifie en argument\n";
		if (EXCErreur.EXCLireValeur() == TropDArguments) cout << "ERREUR : Trop de fichiers specifies en argument (un fichier maximum)\n";
		if (EXCErreur.EXCLireValeur() == FichierInvalide) cout << "ERREUR : Le fichier ne correspond pas au fichier attendu\n";
	}
}