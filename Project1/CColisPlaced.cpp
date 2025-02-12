#ifndef CColisPlaced_cpp
#define CColisPlaced_cpp

#include "CColisPlaced.h"

/// <summary>
/// Constructeur de confort de CColisPlaced
/// </summary>
/// <param name="COLColis"></param>
/// <param name="uiPosX"></param>
/// <param name="uiPosY"></param>
CColisPlaced::CColisPlaced(const CColis& COLColis, unsigned int uiPosX, unsigned int uiPosY)
{
	COLCOLPColis = COLColis;
	uiCOLPposX = uiPosX;
	uiCOLPposY = uiPosY;
};

/// <summary>
/// Accesseur du colis.
/// </summary>
/// <returns>Le colis</returns>
CColis& CColisPlaced::COLPGetColis()
{
	return COLCOLPColis;
}


/// <summary>
/// Accesseur direct en lecture de la position X.
/// </summary>
/// <returns>La position X</returns>
int CColisPlaced::COLPLirePosX() const
{
	return uiCOLPposX;
};

/// <summary>
/// Accesseur direct en lecture de la position Y.
/// </summary>
/// <returns>La position Y</returns>
int CColisPlaced::COLPLirePosY() const
{
	return uiCOLPposY;
};

/// <summary>
/// Accesseur direct en écriture de la position X.
/// </summary>
void CColisPlaced::COLPModifierPosX(unsigned int uiposX)
{
	uiCOLPposX = uiposX;
};

/// <summary>
/// Accesseur direct en écriture de la position Y.
/// </summary>
void CColisPlaced::COLPModifierPosY(unsigned int uiposY)
{
	uiCOLPposY = uiposY;
};

/// <summary>
/// Transforme le colis placé en json.
/// </summary>
/// <returns>Le colis au format json.</returns>
nlohmann::json CColisPlaced::ToJSON() const
{
	return {
		
		{"posX",uiCOLPposX},
		{"posY",uiCOLPposY},
		{"sizeX",COLCOLPColis.COLLireLargeur()},
		{"sizeY",COLCOLPColis.COLLireLongueur()},
		{"numCommande",COLCOLPColis.COLLireNumeroDeCommande() },
	};
}
#endif