#ifndef CException_h
#define CException_h
constexpr auto PAS_ERREUR = 0;

class CException
{
private:
	unsigned int uiEXCValeur;
public:
	/*************************************************************
	***** CEXCEPTION : Constructeur par défaut de CException *****
	**************************************************************
	***** Entrée : ***********************************************
	***** Nécessite : ********************************************
	***** Sortie : ***********************************************
	***** Entraîne : Le constructeur a initialisé un objet ********
	***** CException avec uiEXCValeur = PAS_ERREUR ***************
	*************************************************************/
	CException();

	/*********************************************************************
	***** EXCLIREVALEUR : Accesseur direct en lecture de uiEXCValeur *****
	**********************************************************************
	***** Entrée : *******************************************************
	***** Nécessite : ****************************************************
	***** Sortie : Valeur de l'attribut uiEXCValeur **********************
	***** Entraîne : EXCLireValeur() = uiEXCValeur ***********************
	*********************************************************************/
	const unsigned int EXCLireValeur() const;
	/********************************************************************************
	***** EXCMODIFIERVALEUR : Accesseur direct en écriture de uiEXCValeur ***********
	*********************************************************************************
	***** Entrée : uiValeur, entier non signé, nouvelle valeur pour uiEXCValeur *****
	***** Nécessite : uiValeur est un entier positif ********************************
	***** Sortie : ******************************************************************
	***** Entraîne : uiEXCValeur = uiValeur *****************************************
	********************************************************************************/
	void EXCModifierValeur(unsigned int uiValeur);
};


/*********************************************************************
***** EXCLIREVALEUR : Accesseur direct en lecture de uiEXCValeur *****
**********************************************************************
***** Entrée : *******************************************************
***** Nécessite : ****************************************************
***** Sortie : Valeur de l'attribut uiEXCValeur **********************
***** Entraîne : EXCLireValeur() = uiEXCValeur ***********************
*********************************************************************/
const inline unsigned int CException::EXCLireValeur() const
{
	return uiEXCValeur;
}

/********************************************************************************
***** EXCMODIFIERVALEUR : Accesseur direct en écriture de uiEXCValeur ***********
*********************************************************************************
***** Entrée : uiValeur, entier non signé, nouvelle valeur pour uiEXCValeur *****
***** Nécessite : uiValeur est un entier positif ********************************
***** Sortie : ******************************************************************
***** Entraîne : uiEXCValeur = uiValeur *****************************************
********************************************************************************/
inline void CException::EXCModifierValeur(unsigned int uiValeur)
{
	uiEXCValeur = uiValeur;
}

#endif#pragma once
