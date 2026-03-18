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
using namespace std;




//NiveauAcces est une enumeration pour savoir a quel titre l'utilisateur souhaite se connecter
enum NiveauAcces {
	ADMIN,
	UTILISATEUR,
	INVITE
};
//Structure Utilisateur qui contiendra les informations sur l'utilisateur, son niveau d'acces et son nombre de tentative de connection
struct Utilisateur{

	string nom;
	string motDePasse;
	NiveauAcces niveau;
	int tentativesConnexion = 0;

};


int main() {

	// Message pour l'utilisateur
	cout << "----------Mini systeme de securite-----------"<<endl;
	cout << "---------------gestion des acces---------------" << endl;
	cout << endl << endl << endl;

	//DEFENIR LA VARIABLE QUI VAS CONTENIR LE NOMBRE D'UTILISATEUR QUE VAS CONTENIR LE SYSTEME
	int nombre_utilisateur;

	cout << "Veuillez entrez le nombre d'utilisateurs qui seront enregistrer : ";
	cin >> nombre_utilisateur;
	
	Utilisateur* utilisateurs = new Utilisateur[nombre_utilisateur];

	int tentativesConnexion = 0;
	
	for (int i = 0; i < nombre_utilisateur; i++) {

		cout << "Nom : ";
		cin >> utilisateurs[i].nom;
		cout << endl;
		cout << "Mot de passe : ";
		cin >> utilisateurs[i].motDePasse;
		cout << endl;

		// choix est le variable pour identifier le niveau d'acces de l'utilisateur
		int choix ;
		cout << "Veuillez choisir votre niveau d'acces :\n0 : ADMIN\n1 : UTILISATEUR\n2 : INVITE\n";
		cout << endl;
		cout << "Choix : ";
		cin >> choix;
		cout << endl;
		utilisateurs[i].niveau = (NiveauAcces)choix;

		
	}

	//OUVRIR LE FICHER LOGS_SECURITE.TXT
	ofstream ficher("logs_securite.txt");


	//SIMULATILON DE CONNEXION


	//BOUCLE WHILE POUR QUE L'UTILISAITEUR AIT 3 ESSAIS
	while (tentativesConnexion < 3) {


		cout << endl << endl << endl;
		cout << "Nom : ";
		string nom_de_utilisateur;
		cin >> nom_de_utilisateur;
		string mot_de_passe_utilisateur;
		cout << endl,
			cout << "Mot de passe : ";
		cin >> mot_de_passe_utilisateur;
		cout << endl;


		 // BOUCLE FOR POUR PARCOURIR LE TABLEAU ET VERIFICATION DE NOM && MOT DE PASSE DE L'UTILISATEUR

		for (int i = 0; i < nombre_utilisateur; i++) {

			

			if (utilisateurs[i].nom == nom_de_utilisateur) {
				if (utilisateurs[i].motDePasse == mot_de_passe_utilisateur) {
					cout << "Acces autorise.";
					break;
					cout << endl;
					
				}
				else if (utilisateurs[i].motDePasse != mot_de_passe_utilisateur) {
					utilisateurs[i].tentativesConnexion++;
					cout << "Paramètres invalide.";
					if (utilisateurs[i].tentativesConnexion >= 3) {

						cout << "Compte bloqué." << endl;

						break;

					}
				
			    }


			   

			}

			

			ficher << utilisateurs[i].nom << " " << endl << utilisateurs[i].tentativesConnexion << " " << endl << utilisateurs[i].niveau;

		}

		  tentativesConnexion += 1 ;
	}







	 delete[] utilisateurs;
	 ficher.close();

	return 0;
}