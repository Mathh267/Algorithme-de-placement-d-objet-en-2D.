#ifndef Algo_cpp
#define Algo_cpp



#include "CException.h"
#include "CCommande.h"
#include "CColisPlaced.h"
#include "CSegment.h"
#include <iostream>
#include <ranges>
#include <regex>

constexpr auto ListeCommandeVide = 4;

using namespace std;


/// <summary>
/// Fonction permettant de faire la comparaison entre deux segments
/// </summary>
/// <param name="s1"></param>
/// <param name="s2"></param>
/// <returns></returns>
static bool compSegment(const CSegment& s1, const CSegment& s2)
{
	if (s1.LirePosY() == s2.LirePosY())
	{
		return s1.LirePosX() < s2.LirePosX();
	}
	else
	{
		return s1.LirePosY() < s2.LirePosY();
	}
}


static void EnleverDoublon(vector<CSegment>& ListeDesSegments)
{
	int i = 0;
	while (i < ListeDesSegments.size() - 1) {
		int k = i + 1;
		while (k < ListeDesSegments.size())
		{
			if ((ListeDesSegments[i].LirePosX() + ListeDesSegments[i].LireLargeur() == ListeDesSegments[k].LirePosX()) && ListeDesSegments[k].LirePosY() == ListeDesSegments[i].LirePosY() && !ListeDesSegments[k].LireIfPorteur())
			{
				ListeDesSegments[i].ModifierLargeur(ListeDesSegments[i].LireLargeur() + ListeDesSegments[k].LireLargeur());
				ListeDesSegments.erase(ListeDesSegments.begin() + k);
			}
			else
			{
				k++;
			}
		}
		i++;
	}
}

/// <summary>
/// To Do Fait le placement des colis à chaque Colis.
/// </summary>
/// <param name="ListeDesColisPlacée"></param>
/// <param name="ListeDesSegments"></param>
/// <param name="ColisAPlacer"></param>
static void Placement(vector<CColisPlaced>& ListeDesColisPlacée, vector<CSegment>& ListeDesSegments, CColis& ColisAPlacer,unsigned int uiLongueur,unsigned int uiLargeur, vector<CColis>& ListeDesColisNonPlacée)
{
	sort(ListeDesSegments.begin(), ListeDesSegments.end(), compSegment);
	int count = 1;
	for (auto& Segment : ListeDesSegments) 
	{
		cout << "Le" << count << " Segment à comme position: " << Segment.LirePosX() << " X et " << Segment.LirePosY() << " et une largeur de " << Segment.LireLargeur() << endl;
	}
	cout << endl;
	bool Placed = false;
	if (true)
	{
		int i = 0;
		while (!Placed && i < ListeDesSegments.size())
		{
			if (ListeDesSegments[i].LireIfPorteur()) 
			{
				if ((ColisAPlacer.COLLireLargeur() + ListeDesSegments[i].LirePosX()) <= (int) uiLargeur && (ColisAPlacer.COLLireLongueur() + ListeDesSegments[i].LirePosY()) <= (int) uiLongueur)
				{
					if ((ColisAPlacer.COLLireLargeur() <= ListeDesSegments[i].LireLargeur()))
					{
						CColisPlaced ColisPlaced(ColisAPlacer, ListeDesSegments[i].LirePosX(), ListeDesSegments[i].LirePosY());
						if (ColisAPlacer.COLLireLargeur() == ListeDesSegments[i].LireLargeur())
						{
							ListeDesSegments.erase(ListeDesSegments.begin() + i);
						}
						else
						{
							ListeDesSegments[i].ModifierPosX(ListeDesSegments[i].LirePosX() + ColisAPlacer.COLLireLargeur());
							ListeDesSegments[i].ModifierLargeur(ListeDesSegments[i].LireLargeur() - ColisAPlacer.COLLireLargeur());
						}
						CSegment NouveauSegment(ColisPlaced.COLPLirePosX(), ColisPlaced.COLPLirePosY()+ColisAPlacer.COLLireLongueur(), ColisAPlacer.COLLireLargeur(), true);
						ListeDesSegments.push_back(NouveauSegment);
						ListeDesColisPlacée.push_back(ColisPlaced);
						Placed = true;
					}
					else 
					{
							vector<CSegment*> ListeDesSegmentsPourPlacement;
							vector<int> ListePositionSegments;
							int LargeurMax = ListeDesSegments[i].LireLargeur();
							ListeDesSegmentsPourPlacement.push_back(&ListeDesSegments[i]);
							ListePositionSegments.push_back(i);
							size_t sizebefore = 0;
							while (sizebefore < ListeDesSegmentsPourPlacement.size())
							{
								sizebefore = ListeDesSegmentsPourPlacement.size();
								int IterateurSegments = 0;
								bool find = false;
								int PosY = (*ListeDesSegmentsPourPlacement[ListeDesSegmentsPourPlacement.size() - 1]).LirePosY();
								int PosX = (*ListeDesSegmentsPourPlacement[ListeDesSegmentsPourPlacement.size() - 1]).LirePosX() + (*ListeDesSegmentsPourPlacement[ListeDesSegmentsPourPlacement.size() - 1]).LireLargeur();
								while (IterateurSegments < ListeDesSegments.size() && !find)
								{
									if (PosY >= ListeDesSegments[IterateurSegments].LirePosY() && PosX == ListeDesSegments[IterateurSegments].LirePosX())
									{
										ListeDesSegmentsPourPlacement.push_back(&ListeDesSegments[IterateurSegments]);
										ListePositionSegments.push_back(IterateurSegments);
										LargeurMax += ListeDesSegments[IterateurSegments].LireLargeur();
										find = true;
									}
									IterateurSegments++;
								}
							}
							for (auto& Segment : ListeDesSegmentsPourPlacement)
							{
								cout << "Le" << count << " Segment pour le placement à comme position: " << (*Segment).LirePosX() << " X et " << (*Segment).LirePosY() << " et une largeur de " << (*Segment).LireLargeur() << endl;
							}
							cout << endl;
							if (LargeurMax >= ColisAPlacer.COLLireLargeur())
							{
							CColisPlaced ColisPlaced(ColisAPlacer, ListeDesSegments[i].LirePosX(), ListeDesSegments[i].LirePosY());
							int Largeur = ColisAPlacer.COLLireLargeur();
							int ProchaineLargeur = (*ListeDesSegmentsPourPlacement[0]).LireLargeur();
							while (Largeur >= ProchaineLargeur)
							{
								Largeur -= (*ListeDesSegmentsPourPlacement[0]).LireLargeur();
								ListeDesSegmentsPourPlacement.erase(ListeDesSegmentsPourPlacement.begin());
								int Position = ListePositionSegments[0];
								ListePositionSegments.erase(ListePositionSegments.begin());
								ListeDesSegments.erase(ListeDesSegments.begin() + Position);
								for (auto& item : ListePositionSegments)
								{
									if (Position < item)
									{
										item--;
									}
								}
								if (ListeDesSegmentsPourPlacement.size() != 0) 
								{
									ProchaineLargeur = (*ListeDesSegmentsPourPlacement[0]).LireLargeur();
								}
								else 
								{
									ProchaineLargeur = 99999;
								}
							}
							if (ListeDesSegmentsPourPlacement.size() != 0)
							{
								ListeDesSegments[ListePositionSegments[0]].ModifierPosX(ListeDesSegments[ListePositionSegments[0]].LirePosX() + Largeur);
								ListeDesSegments[ListePositionSegments[0]].ModifierLargeur(ListeDesSegments[ListePositionSegments[0]].LireLargeur() - Largeur);
							}
							CSegment NouveauSegment(ColisPlaced.COLPLirePosX(), ColisPlaced.COLPLirePosY() + ColisAPlacer.COLLireLongueur(), ColisAPlacer.COLLireLargeur(), true);
							//cout << "Nouveau Segment à pos X : " << NouveauSegment.LirePosY() << endl;
							ListeDesSegments.push_back(NouveauSegment);
							ListeDesColisPlacée.push_back(ColisPlaced);
							Placed = true;
						}
					}
				}
			}
			i++;
		}
		if (!Placed)
		{
			cout << "Erreur Colis Non Placé" << endl;
			ListeDesColisNonPlacée.push_back(ColisAPlacer);
		}
		EnleverDoublon(ListeDesSegments);
	}
	else
	{
		//TODO
	}
}


static vector<CColisPlaced> Algorithme(vector<CCommande> ListeDeCommande,unsigned int uiLongueur,unsigned int uiLargeur)
{
	try 
	{
		if (ListeDeCommande.size() == 0)
		{
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(ListeCommandeVide);
			throw EXCErreur;
		}
		// Initialisation des listes.
		vector<CColisPlaced> ListeDesColisPlacée;
		vector<CSegment> ListeDesSegments;
		vector<CColis> ListeDesColisNonPlacée;
		CSegment SegmentDepart(0, 0, uiLargeur, true);
		ListeDesSegments.push_back(SegmentDepart);
		int countPlacement = 1;
		for (auto& Commande : ListeDeCommande)
		{
			for (auto& Colis : Commande.COMLireListeColis())
			{
				cout << countPlacement << endl;
				cout << "Colis de largeur " << Colis.COLLireLargeur() << " et de longueur" << Colis.COLLireLongueur() << endl;
				Placement(ListeDesColisPlacée, ListeDesSegments, Colis,uiLongueur,uiLargeur,ListeDesColisNonPlacée);
				cout << endl;
				countPlacement++;
			}
		}
		for (auto& item : ListeDesColisPlacée)
		{
			cout << "Un colis de la commande: " << item.COLPGetColis().COLLireNumeroDeCommande() << " est place a la position: " << item.COLPLirePosX() << " x et " << item.COLPLirePosY() << "y." << endl;
		}

		for (auto& item : ListeDesColisNonPlacée)
		{
			cout << "Un Colis n'as pas été réussi à être placée de la commande " << item.COLLireNumeroDeCommande() << endl;
		}

		return ListeDesColisPlacée;
		

	}
	
	catch (CException EXCErreur)
	{
		if (EXCErreur.EXCLireValeur() == ListeCommandeVide) cout << "ERREUR : Il n'y a pas de commande\n";
	}
	
}






#endif // !Algo_cpp