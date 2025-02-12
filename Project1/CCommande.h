#ifndef CCommande_h
#define CCommande_h

#include <fstream>
#include <string>
#include <vector>
#include "CColis.h"

/// <summary>
/// Classe représentant une commande d'un client à mettre dans une remorque.
/// </summary>
class CCommande
{
private:
	unsigned int uiCOMNumeroCommande; //Numéro de la commande.
	std::string strCOMNomClient; //Nom du client de la commande.
	std::vector<CColis> vecCOMListeColis; // Liste des colis associé à la commande.

public:
	
	/// <summary>
	/// Constructeur par défaut de CCommande.
	/// </summary>
	CCommande();

	/// <summary>
	/// Constructeur de confort de CCommande
	/// </summary>
	/// <param name="uiNumeroCommande"> Le numéro de commande à modifier</param>
	/// <param name="strNomClient"> Le nom du client de la commande</param>
	/// <param name="lisListeColis"> La liste des colis</param>
	CCommande(unsigned int uiNumeroCommande, std::string strNomClient);

	/// <summary>
	/// Accesseur direct en lecture de uiCOMNumeroCommande
	/// </summary>
	/// <returns>Le numéro de commande de la commande </returns>
	int COMLireNumeroCommande() const;

	/// <summary>
	/// Accesseur direct en lecture de strCOMNomClient
	/// </summary>
	/// <returns>Le nom du client de la commande</returns>
	std::string COMLireNomClient() const;

	/// <summary>
	/// Accesseur direct en lecture de vecCOMListeColis
	/// </summary>
	/// <returns>La liste des colis</returns>
	std::vector<CColis> COMLireListeColis() const;

	/// <summary>
	/// Accesseur direct en écriture de vecCOMListeColis
	/// </summary>
	/// <param name="vecListeColis">Le vecteur de colis à remplacer</param>
	void COMModifierListeColis(std::vector<CColis> vecListeColis);
};

#endif#pragma once
