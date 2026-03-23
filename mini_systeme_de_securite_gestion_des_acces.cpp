//Toure Mikailou Cedric
//Université De Moncton 
//Département d'informatique

/*Mini système de sécurité (gestion des accès)


Un système de sécurité informatique qui gère des utilisateurs et leurs tentatives de connexion


STRUCTURE


1) ENUMERATION DU NIVEAU D'ACCES
2) STRUCTURE UTILISATEUR
3) TABLEAU DYNAMIQUE
4) ENRREGISTREMENT DES UTILISATEURS
5) SIMULATION DE CONNECXION
6) SAUVEGARDE DANS UN FICHER
7) TRI DE SECURIE
8) GESTION D'ERREUR


*/

#include <iostream>
#include<string>
#include<fstream>
#include<stdexcept>
using namespace std;



//NiveauAcces est une énumeration pour savoir a quel titre l'utilisateur souhaite se connecter
enum NiveauAcces {
	ADMIN,
	UTILISATEUR,
	INVITE
};
//Structure Utilisateur qui contiendra les informations sur l'utilisateur, son niveau d'acces et son nombre de tentative de connection
struct Utilisateur {

	string nom;
	string motDePasse;
	NiveauAcces niveau;
	int tentativesConnexion = 0;

};
// Fonction de tri a bulle pour trier les utilisateurs en fonction de leur nombre de tentative de connexion
void tri_a_bulle(Utilisateur utilisateurs[], int nombre_utilisateur) {

	for (int i = 0; i < nombre_utilisateur - 1; i++) {

		for (int j = 0; j < nombre_utilisateur - i - 1; j++) {

			if (utilisateurs[j].tentativesConnexion < utilisateurs[j + 1].tentativesConnexion) {

				Utilisateur tmp = utilisateurs[j];
				utilisateurs[j] = utilisateurs[j + 1];
				utilisateurs[j + 1] = tmp;

			}
		}
	}
}

int main() {

	// Message pour l'utilisateur
	cout << "00000000-------------------------------------Mini systeme de securite------------------------------------------000000001" << endl;
	cout << "00000000----------------------------------------gestion des acces----------------------------------------------000000001" << endl;
	cout << endl << endl << endl<<endl<<endl;

	//DEFENIR LA VARIABLE QUI VAS CONTENIR LE NOMBRE D'UTILISATEUR QUE VAS CONTENIR LE SYSTEME
	int nombre_utilisateur;

	cout << "Veuillez entrez le nombre d'utilisateur(s) qui seront enregistrer : ";
	cin >> nombre_utilisateur;
	cout << endl;

	Utilisateur* utilisateurs = new Utilisateur[nombre_utilisateur];

	int tentativesConnexion = 0;
	


	for (int i = 0; i < nombre_utilisateur; i++) {
		 
		cout << endl;
		cout << endl;
		cout << "Utilisateur " << i + 1 << "  " << endl;
		cout << endl;
		cout << "Nom : ";
		cin >> utilisateurs[i].nom;
		cout << endl;
		cout << "Mot de passe : ";
		cin >> utilisateurs[i].motDePasse;
		cout << endl;
		cout << endl;

		// choix est le variable pour identifier le niveau d'acces de l'utilisateur

		int choix;

		cout << "Veuillez choisir votre niveau d'acces :\n\n0 : ADMIN\n1 : UTILISATEUR\n2 : INVITE\n";
		cout << endl;
		cout << endl;
		cout << "Code du niveau d'acces : ";
		cin >> choix;
		
		utilisateurs[i].niveau = (NiveauAcces)choix;


	}

	//OUVRIR LE FICHER LOGS_SECURITE.TXT
	ofstream ficher("logs_securite.txt");


	//SIMULATILON DE CONNEXION

	cout << endl << endl << endl << endl;
	cout << "**********************************************\n**********************************************\n**********************************************\n**********************************************\n**********************************************\n**********************************************\n**********************************************\n**********************************************\n**********************************************\n**********************************************\n**********************************************\n**********************************************\n**********************************************\n**********************************************\n**********************************************\n**********************************************\n**********************************************\n**********************************************\n**********************************************\n**********************************************";
	
	//BOUCLE WHILE POUR QUE L'UTILISAITEUR FASSE 3 ESSAIS

	while (tentativesConnexion < 3) {


		cout << "\n\n\n\nVeuillez vous connecter  " << endl<<endl<< endl<<endl;
		cout << "Nom : ";
		string nom_de_utilisateur;
		cin >> nom_de_utilisateur;
		string mot_de_passe_utilisateur;
		cout << endl,
			cout << "Mot de passe : ";
		cin >> mot_de_passe_utilisateur;
		cout << endl;


		// Variable pour savoir si l'utilisateur existe.
		bool trouve = false; 

		
		// BOUCLE FOR POUR PARCOURIR LE TABLEAU ET VERIFICATION DE NOM && MOT DE PASSE DE L'UTILISATEUR

			for (int i = 0; i < nombre_utilisateur; i++) {



				if (utilisateurs[i].nom == nom_de_utilisateur) {

					trouve = true;

					if (utilisateurs[i].motDePasse == mot_de_passe_utilisateur) {

						cout << "Acces autorise.";
						break;
						cout << endl;

					}

					else if (utilisateurs[i].motDePasse != mot_de_passe_utilisateur) {

						utilisateurs[i].tentativesConnexion++;
						cout << "Paramètre (s) invalide &&";
						cout << " Tentative(s) " << utilisateurs[i].tentativesConnexion << "\n";
						if (utilisateurs[i].tentativesConnexion >= 3) {

							cout << "\n\nVotre compte est bloquer.";
							
				
						}

					}

				

				}

				ficher << utilisateurs[i].nom << " " << endl << utilisateurs[i].tentativesConnexion << " " << endl << utilisateurs[i].niveau;

				
			}

			if (!trouve) {
				cout << "Utilisateur non trouve." << endl;
			
			}
		
			tentativesConnexion++;


	}
	

	tri_a_bulle(utilisateurs, nombre_utilisateur); // Appel de la fonction de tri a bulle pour trier les utilisateurs en fonction de leur nombre de tentative de connexion
	

	// Affichage des utilisateurs tries par nombre de tentatives de connexion
	cout << "\n\n\n\n\n\nUtilisateurs tries par nombre de tentatives :\n\n\n";

	for (int i = 0; i < nombre_utilisateur; i++) {
		cout << utilisateurs[i].nom << " - Tentatives : "
			<< utilisateurs[i].tentativesConnexion << endl;
	}

	delete[] utilisateurs; // Liberer l'espace memoire utilser par le tableau
	ficher.close(); // Fermer le ficher log.txt
	
	return 0;
}


//Fin du programme






 

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


                                                                                           





