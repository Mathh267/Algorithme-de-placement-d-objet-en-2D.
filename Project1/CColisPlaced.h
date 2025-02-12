#ifndef CColisPlaced_h
#define CColisPlaced_h

#include "CColis.h"
#include <nlohmann/json.hpp>

class CColisPlaced
{
private:
	CColis COLCOLPColis;
	unsigned int uiCOLPposX;
	unsigned int uiCOLPposY;
public:
	
	/// <summary>
	/// Constructeur de confort de CColisPlaced
	/// </summary>
	/// <param name="COLColis"></param>
	/// <param name="uiPosX"></param>
	/// <param name="uiPosY"></param>
	CColisPlaced(const CColis& COLColis, unsigned int uiPosX, unsigned int uiPosY);
	
	/// <summary>
	/// Accesseur du colis.
	/// </summary>
	/// <returns>Le colis</returns>
	CColis& COLPGetColis();

	/// <summary>
	/// Accesseur direct en lecture de la position X.
	/// </summary>
	/// <returns>La position X</returns>
	int COLPLirePosX() const;

	/// <summary>
	/// Accesseur direct en lecture de la position Y.
	/// </summary>
	/// <returns>La position Y</returns>
	int COLPLirePosY() const;

	/// <summary>
	/// Accesseur direct en écriture de la position X.
	/// </summary>
	void COLPModifierPosX(unsigned int uiposX);

	/// <summary>
	/// Accesseur direct en écriture de la position Y.
	/// </summary>
	void COLPModifierPosY(unsigned int uiposY);

	/// <summary>
	/// Transforme le colis placé en json.
	/// </summary>
	/// <returns>Le colis au format json.</returns>
	nlohmann::json ToJSON() const;
};

#endif 
#pragma once
