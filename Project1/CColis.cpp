#ifndef CColis_cpp
#define CColis_cpp

#include "CColis.h"

/// <summary>
/// Constructeur par défaut de CColis.
/// </summary>
CColis::CColis()
{
	uiCOLHauteur = 0;
	uiCOLLargeur = 0;
	uiCOLLongeur = 0;
	uiCOLNumeroDeCommande = 0;
	uiCOLPoids = 0;
	uiCOLNbColis = 0;
};

/// <summary>
/// Constructeur de confort de CColis
/// </summary>
CColis::CColis(unsigned int uiLongeur, unsigned int uiLargeur, unsigned int uiHauteur, unsigned int uiPoids, unsigned int uiNumeroDeCommande,unsigned int uiNbColis)
{
	uiCOLLongeur = uiLongeur;
	uiCOLLargeur = uiLargeur;
	uiCOLHauteur = uiHauteur;
	uiCOLPoids = uiPoids;
	uiCOLNumeroDeCommande = uiNumeroDeCommande;
	uiCOLNbColis = uiNbColis;
};


/// <summary>
/// Accesseur direct en lecture de uiCOLLongueur
/// </summary>
/// <returns>La longueur du colis</returns>
int CColis::COLLireLongueur() const
{
	return uiCOLLongeur;
};

/// <summary>
/// Accesseur direct en lecture de uiCOLLargeur
/// </summary>
/// <returns>La largeur du colis</returns>
int CColis::COLLireLargeur() const
{
	return uiCOLLargeur;
};

/// <summary>
/// Accesseur direct en lecture de uiCOLHauteur
/// </summary>
/// <returns>La hauteur du colis</returns>
int CColis::COLLireHauteur() const
{
	return uiCOLHauteur;
};

/// <summary>
/// Accesseur direct en lecture de uiCOLPoids
/// </summary>
/// <returns>Le poids du colis</returns>
int CColis::COLLirePoids() const
{
	return uiCOLPoids;
};

/// <summary>
/// Accesseur direct en lecture de uiCOLNumeroDeCommande
/// </summary>
/// <returns>Le numéro de commande associé au colis</returns>
int CColis::COLLireNumeroDeCommande() const
{
	return uiCOLNumeroDeCommande;
};

/// <summary>
/// Accesseur direct en lecture de uiCOLNumeroDeCommande
/// </summary>
/// <returns>Le numéro de commande associé au colis</returns>
int CColis::COLLireNbColis() const
{
	return uiCOLNbColis;
};

#endif