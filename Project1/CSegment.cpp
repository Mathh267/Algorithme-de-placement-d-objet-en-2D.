#ifndef CSegment_cpp
#define CSegment_cpp

#include "CSegment.h"

/// <summary>
/// Constructeur par default de CSegment
/// </summary>
CSegment::CSegment()
{
	uiSEGLargeur = 0;
	uiSEGposX = 0;
	uiSEGposY = 0;
	bSEGPorteur = false;
};

/// <summary>
/// Constructeur de confort de CSegment
/// </summary>
/// <param name="uiPosX">Position x du segment</param>
/// <param name="uiPosY">Position y du segment</param>
/// <param name="uiLargeur">Largeur du segment</param>
/// <param name="bPorteur">Booléen pour savoir si le segment est porteur</param>
CSegment::CSegment(unsigned int uiPosX, unsigned int uiPosY, unsigned int uiLargeur, bool bPorteur)
{
	uiSEGLargeur = uiLargeur;
	uiSEGposX = uiPosX;
	uiSEGposY = uiPosY;
	bSEGPorteur = bPorteur;
};

/// <summary>
/// Accès en lecture de la position X
/// </summary>
/// <returns>La position X</returns>
int CSegment::LirePosX() const
{
	return uiSEGposX;
};

/// <summary>
/// Accès en lecture de la position Y
/// </summary>
/// <returns>La position Y</returns>
int CSegment::LirePosY() const
{
	return uiSEGposY;
};
/// <summary>
/// Accès en lecture de la largeur du segment
/// </summary>
/// <returns>La largeur</returns>
int CSegment::LireLargeur() const
{
	return uiSEGLargeur;
};

/// <summary>
/// Accès en lecture du booléen signifiant si le segment est porté par un colis/arrière du véhicule.
/// </summary>
/// <returns>Le booléen</returns>
bool CSegment::LireIfPorteur() const
{
	return bSEGPorteur;
};

/// <summary>
/// Accès en écriture de la position X
/// </summary>
void CSegment::ModifierPosX(unsigned int uiPosX)
{
	uiSEGposX = uiPosX;
};

/// <summary>
/// Accès en écriture de la position Y
/// </summary>
void CSegment::ModifierPosY(unsigned int uiPosY)
{
	uiSEGposY = uiPosY;
};

/// <summary>
/// Accès en écriture de la largeur du segment
/// </summary>
void CSegment::ModifierLargeur(unsigned int uiLargeur)
{
	uiSEGLargeur = uiLargeur;
};
/// <summary>
/// Accès en lecture du booléen signifiant si le segment est porté par un colis/arrière du véhicule.
/// </summary>
void CSegment::ModifierIfPorteur(bool bIfPorteur)
{
	bSEGPorteur = bIfPorteur;
}



#endif