#ifndef CCommande_cpp
#define CCommande_cpp

#include "CCommande.h"


/// <summary>
/// Constructeur par défaut de CCommande.
/// </summary>
CCommande::CCommande()
{
	uiCOMNumeroCommande = 0;
	strCOMNomClient = "";
};

/// <summary>
/// Constructeur de confort de CCommande
/// </summary>
/// <param name="uiNumeroCommande"> Le numéro de commande à modifier</param>
/// <param name="strNomClient"> Le nom du client de la commande</param>
/// <param name="lisListeColis"> La liste des colis</param>
CCommande::CCommande(unsigned int uiNumeroCommande, std::string strNomClient)
{
	uiCOMNumeroCommande = uiNumeroCommande;
	strCOMNomClient = strNomClient;
};

/// <summary>
/// Accesseur direct en lecture de uiCOMNumeroCommande
/// </summary>
/// <returns>Le numéro de commande de la commande </returns>
int CCommande::COMLireNumeroCommande() const
{
	return uiCOMNumeroCommande;
};

/// <summary>
/// Accesseur direct en lecture de strCOMNomClient
/// </summary>
/// <returns>Le nom du client de la commande</returns>
std::string CCommande::COMLireNomClient() const
{
	return strCOMNomClient;
};

/// <summary>
	/// Accesseur direct en lecture de vecCOMListeColis
	/// </summary>
	/// <returns>La liste des colis</returns>
std::vector<CColis> CCommande::COMLireListeColis() const
{
	return vecCOMListeColis;
};

/// <summary>
/// Accesseur direct en écriture de vecCOMListeColis
/// </summary>
/// <param name="vecListeColis">Le vecteur de colis à remplacer</param>
void CCommande::COMModifierListeColis(std::vector<CColis> vecListeColis)
{
	vecCOMListeColis = vecListeColis;
}




#endif