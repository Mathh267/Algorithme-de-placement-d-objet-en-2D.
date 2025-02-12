#ifndef CSegment_h
#define CSegment_h


class CSegment
{

private:

	unsigned int uiSEGposX;
	unsigned int uiSEGposY;
	unsigned int uiSEGLargeur;
	bool bSEGPorteur;

public:
	
	/// <summary>
	/// Constructeur par default de CSegment
	/// </summary>
	CSegment();
	
	/// <summary>
	/// Constructeur de confort de CSegment
	/// </summary>
	/// <param name="uiPosX">Position x du segment</param>
	/// <param name="uiPosY">Position y du segment</param>
	/// <param name="uiLargeur">Largeur du segment</param>
	/// <param name="bPorteur">Booléen pour savoir si le segment est porteur</param>
	CSegment(unsigned int uiPosX, unsigned int uiPosY, unsigned int uiLargeur, bool bPorteur);

	/// <summary>
	/// Accès en lecture de la position X
	/// </summary>
	/// <returns>La position X</returns>
	int LirePosX() const;
	/// <summary>
	/// Accès en lecture de la position Y
	/// </summary>
	/// <returns>La position Y</returns>
	int LirePosY() const;
	/// <summary>
	/// Accès en lecture de la largeur du segment
	/// </summary>
	/// <returns>La largeur</returns>
	int LireLargeur() const;
	/// <summary>
	/// Accès en lecture du booléen signifiant si le segment est porté par un colis/arrière du véhicule.
	/// </summary>
	/// <returns>Le booléen</returns>
	bool LireIfPorteur() const;

	/// <summary>
	/// Accès en écriture de la position X
	/// </summary>
	void ModifierPosX(unsigned int uiPosX);
	/// <summary>
	/// Accès en écriture de la position Y
	/// </summary>
	void ModifierPosY(unsigned int uiPosY);
	/// <summary>
	/// Accès en écriture de la largeur du segment
	/// </summary>
	void ModifierLargeur(unsigned int uiLargeur);
	/// <summary>
	/// Accès en lecture du booléen signifiant si le segment est porté par un colis/arrière du véhicule.
	/// </summary>
	void ModifierIfPorteur(bool bIfPorteur);





};

#endif