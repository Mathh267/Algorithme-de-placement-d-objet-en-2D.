#ifndef CColis_h
#define CColis_h

#include <fstream>
#include <string>

/// <summary>
/// Classe représentant un colis à être posé dans la remorque.
/// </summary>
class CColis
{
private:
	unsigned int uiCOLLongeur; //Longueur du colis
	unsigned int uiCOLLargeur; //Largeur du colis
	unsigned int uiCOLHauteur; //Hauteur du colis
	unsigned int uiCOLPoids; //Poids du colis
	unsigned int uiCOLNumeroDeCommande; //Numéro de commande associé au colis
	unsigned int uiCOLNbColis;//Nombre de colis associé au colis
public:
	
	/// <summary>
	/// Constructeur par default de CColis.
	/// </summary>
	CColis();

	/// <summary>
	/// Constructeur de confort de CColis
	/// </summary>
	CColis(unsigned int uiLongeur, unsigned int uiLargeur, unsigned int uiHauteur, unsigned int uiPoids, unsigned int uiNumeroDeCommande,unsigned int uiNbColis);

	/// <summary>
	/// Accesseur direct en lecture de uiCOLLongueur
	/// </summary>
	/// <returns>La longueur du colis</returns>
	int COLLireLongueur() const; 

	/// <summary>
	/// Accesseur direct en lecture de uiCOLLargeur
	/// </summary>
	/// <returns>La largeur du colis</returns>
	int COLLireLargeur() const;

	/// <summary>
	/// Accesseur direct en lecture de uiCOLHauteur
	/// </summary>
	/// <returns>La hauteur du colis</returns>
	int COLLireHauteur() const;

	/// <summary>
	/// Accesseur direct en lecture de uiCOLPoids
	/// </summary>
	/// <returns>Le poids du colis</returns>
	int COLLirePoids() const;
	
	/// <summary>
	/// Accesseur direct en lecture de uiCOLNumeroDeCommande
	/// </summary>
	/// <returns>Le numéro de commande associé au colis</returns>
	int COLLireNumeroDeCommande() const;

	/// <summary>
	/// Accesseur direct en lecture de uiCOLNumeroDeCommande
	/// </summary>
	/// <returns>Le numéro de commande associé au colis</returns>
	int COLLireNbColis() const;

};

#endif#pragma once
