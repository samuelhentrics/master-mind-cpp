/*
 Programme : Master Mind
 But :  Deviner une combinaison aléatoire de 4 lettres parmis ABCD en 12 coups maximum
 Date de dernière modification :22/10/2021
 Auteur : Samuel HENTRICS LOISTINE, Cédric ETCHEPARE
*/

#include "game-tools.h"
#include <iostream>
using namespace std;
 
int main(void)
{
    // VARIABLES ***************************************************************************************************************************************************************
    // *************************************************************************************************************************************************************************
    
    const unsigned short int NB_COUPS_MAX = 12; // Nombre de combinaisons maximum que le joueur peut proposer
    const unsigned short int NB_LETTRES_PROP = 4; // Nombre de lettres proposées (A, B, C, D)
    const unsigned short int NB_LETTRES_MAX = 4; // Nombre maximum de lettres proposées dans une combinaison
    
    char combinaisonSaisie [NB_LETTRES_MAX]; // Combinaison saisie par le joueur qui doit deviner la combinaison générée
    char combinaisonGen [NB_LETTRES_MAX]; // Combinaison générée qui doit être deviné par le joueur

    unsigned short int nbOccurLetGen [NB_LETTRES_PROP]; // Nombre d'occurrences de lettres dans la combinaison générée
    unsigned short int nbOccurLetS [NB_LETTRES_PROP]; // Nombre d'occurrences de lettres dans la combinaison saisie
    unsigned short int nbOccurLetSBP [NB_LETTRES_PROP]; // Nombre d'occurrences de lettres bien saisies dans la combinaison saisie

    unsigned short int nbCoups; // Nombre de coups du joueur

    unsigned short int nbLettresBienPlacees; // Nombre de lettres bien placées dans la combinaison proposée par le joueur
    int nbLettresMalPlacees; // Nombre de lettres mal placées dans la combinaison proposée par le joueur

    unsigned short int indiceCaseCourante; // Indice de la case courante des tableaux

    bool trouve; // Determine si le joueur a trouvé la combinaison sans perdre

    // TRAITEMENTS**************************************************************************************************************************************************************
    // *************************************************************************************************************************************************************************

    // NB_LETTRES_PROP, NB_LETTRES_MAX >> initialisationPartie >> nbCoups, trouve, nbLettresBienPlacees, nbLettresMalPlacees, nbOccurLetGen, nbOccurLetS, nbOccurLetSBP, 
    // combinaisonGen **********************************************************************************************************************************************************

    // ****** () >> reglesJeu >> (écran) ***************************************************************************************************************************************
    cout << "M A S T E R M I N D" << endl << endl;

    cout << "Le joueur doit trouver en 12 coups maximum, une combinaison de 4 lettres parmi les lettres : A B C D" << endl;
    cout << "combinaison generee aleatoirement par le jeu" << endl << endl;
    cout << "A chaque proposition du joueur, le jeu informe sur :" << endl;
    cout << " - le nombre de lettres proposees qui sont dans la combinaison, et a la bonne place," << endl;
    cout << " - le nombre de lettres proposees qui sont dans la combinaison, mais pas a la bonne place." << endl << endl;

    // ****** () >> initialisationVariables >> nbCoups, trouve, nbLettresBienPlacees, nbLettresMalPlacees **********************************************************************

    nbCoups = 1;
    trouve = false;
    nbLettresBienPlacees = 0;
    nbLettresMalPlacees = 0;

    // ****** NB_LETTRES_PROP >> initialisationTableauxOccurences >> nbOccurLetGen, nbOccurLetSBP, nbOccurLetS *****************************************************************
    for (indiceCaseCourante = 0; indiceCaseCourante <= NB_LETTRES_PROP-1; indiceCaseCourante++)
    {
        nbOccurLetGen[indiceCaseCourante] = 0;
        nbOccurLetS[indiceCaseCourante] = 0;
        nbOccurLetSBP[indiceCaseCourante] = 0;
    }
    
    // ****** NB_LETTRES_MAX >> genererCombinaison >> combinaisonGen, nbOccurLetGen ********************************************************************************************
    for (indiceCaseCourante = 0; indiceCaseCourante <= NB_LETTRES_MAX-1; indiceCaseCourante++)
    {
        switch (random(1,4))
        {
            case 1:
                // nbOccurLetGen >> generationA >> combinaisonGen, nbOccurLetGen ***********************************************************************************************
                combinaisonGen[indiceCaseCourante]='A';
                nbOccurLetGen[0]++;
                break;
            case 2:
                // nbOccurLetGen >> generationB >> combinaisonGen, nbOccurLetGen ***********************************************************************************************
                combinaisonGen[indiceCaseCourante]='B';
                nbOccurLetGen[1]++;
                break;
            case 3:
                // nbOccurLetGen >> generationC >> combinaisonGen, nbOccurLetGen ***********************************************************************************************
                combinaisonGen[indiceCaseCourante]='C';
                nbOccurLetGen[2]++;
                break;
            case 4:
                // nbOccurLetGen >> generationD >> combinaisonGen, nbOccurLetGen ***********************************************************************************************
                combinaisonGen[indiceCaseCourante]='D';
                nbOccurLetGen[3]++;
                break;
            default:break;      
        }
    }
    
    // combinaisonGen, NB_LETTRES_MAX >> afficherCombinaisonGen >> (écran) *****************************************************************************************************
    cout << "On recherche : ";
    for ( indiceCaseCourante = 0; indiceCaseCourante < NB_LETTRES_MAX; indiceCaseCourante++)
    {
        cout << combinaisonGen[indiceCaseCourante];
    }
    cout << endl << endl;
    

    // nbCoups, trouve, nbLettresBienPlacees, nbLettresMalPlacees, nbOccurLetGen, nbOccurLetS, nbOccurLetSBP, combinaisonGen, NB_LETTRES_MAX, NB_LETTRES_PROP >>
    // jouerPartie >> [trouve], nbCoups ****************************************************************************************************************************************

    while(true){

        // (clavier) >> saisirCombinaison >> combinaisonSaisie *****************************************************************************************************************
        cout << "Coup (" << nbCoups << "/" << NB_COUPS_MAX << "). Saisir 4 caracteres parmis A B C D : ";
        cin >> combinaisonSaisie;

        // combinaisonGen, combinaisonSaisie, NB_LETTRES_MAX, nbLettresBienPlacees, nbOccurLetSBP >> calculNbOccurencesBienPlacees >> nbLettresBienPlacees, nbOccurLetSBP ******
        for (indiceCaseCourante = 0; indiceCaseCourante <= NB_LETTRES_MAX-1; indiceCaseCourante++)
        {
            // combinaisonGen, combinaisonSaisie, indiceCaseCourante, nbLettresBienPlacees, nbOccurLetSBP >> verifSiLettresBienPlacees >> nbLettresBienPlacees, nbOccurLetSBP***
            if (combinaisonGen[indiceCaseCourante]==combinaisonSaisie[indiceCaseCourante])
            {
                // nbLettresBienPlacees >> incrementerNbLettresBienPlacees >> nbLettresBienPlacees *****************************************************************************
                nbLettresBienPlacees++;
                // combinaisonSaisie, indiceCaseCourante, nbOccurLetSBP >> incrementerOccurencesLettresBienPlacees >> nbOccurLetSBP ********************************************
                switch (combinaisonSaisie[indiceCaseCourante])
                {
                    case 'A':
                        nbOccurLetSBP[0]++;
                        break;
                    case 'B':
                        nbOccurLetSBP[1]++;
                        break;
                    case 'C':
                        nbOccurLetSBP[2]++;
                        break;
                    case 'D':
                        nbOccurLetSBP[3]++;
                        break;
                    default:break;
                }
            }
            
        }
        
        // combinaisonSaisie, nbOccurLetS, NB_LETTRES_MAX >> calculNbOccurencesSaisies >> nbOccurLetS *************************************************************************
        
        for (indiceCaseCourante = 0; indiceCaseCourante < NB_LETTRES_MAX; indiceCaseCourante++)
        {
            switch (combinaisonSaisie[indiceCaseCourante])
            {
                case 'A':
                    nbOccurLetS[0]++;
                    break;
                case 'B':
                    nbOccurLetS[1]++;
                    break;
                case 'C':
                    nbOccurLetS[2]++;
                    break;
                case 'D':
                    nbOccurLetS[3]++;
                    break;
                default:break;
            }  
        }

        // nbOccurLetGen, nbOccurLetS, nbOccurLetSBP, NB_LETTRES_MAX, nbLettresMalPlacees >> nombreOccurencesMalPlacees >> nbLettresMalPlacees *******************************
        
        for (indiceCaseCourante = 0; indiceCaseCourante < NB_LETTRES_MAX; indiceCaseCourante++)
        {
            // nbOccurLetGen, NbOccurLetS, nbOccurLetSBP, indiceCaseCourante >> verifierSiNbMalPlaceesCalculable >> nbLettresMalPlacees **************************************
            if (nbOccurLetGen[indiceCaseCourante] != nbOccurLetSBP[indiceCaseCourante] && nbOccurLetS!=0)
            {
                // nbOccurLetGen, NbOccurLetS, nbOccurLetSBP, indiceCaseCourante >> calculerNbMalPlacees >> nbLettresMalPlacees **********************************************
                if (nbOccurLetGen[indiceCaseCourante] >= nbOccurLetS[indiceCaseCourante]){
                    nbLettresMalPlacees += nbOccurLetS[indiceCaseCourante]-nbOccurLetSBP[indiceCaseCourante];
                }
                else{
                    nbLettresMalPlacees += nbOccurLetGen[indiceCaseCourante]-nbOccurLetSBP[indiceCaseCourante];
                }
            }
            
        }
        
        // nbLettresBienPlacees, nbLettresMalPlacees >> afficherLettresBienEtMalPlacees >> (écran) ***************************************************************************
        cout << nbLettresBienPlacees <<" bien places " << nbLettresMalPlacees << " mal places" << endl <<endl;

        // nbLettresBienPlacees, NB_LETTRES_MAX >> combinaisonEstTrouvee >> [trouve] *****************************************************************************************
        if (nbLettresBienPlacees == NB_LETTRES_MAX){trouve = true; break;}

        // nbCoups, NB_COUPS_MAX >> coupsMAXAtteint >> () ********************************************************************************************************************
        if (nbCoups == NB_COUPS_MAX){break;}

        // NB_LETTRES_PROP, nbCoups >> reinitialisationVariablesEtTableaux >> nbCoups, nbOccurLetSBP, nbOccurLetS, nbLettresBienPlacees, nbLettresMalPlacees *****************

        // *** nbCoups >> incrementerNbCoups >> nbCoups***********************************************************************************************************************
        nbCoups++;
        // *** NB_LETTRES_PROP >> reinitialisationTableauxOccurencesLettres >> nbOccurLetSBP, nbOccurLetS ********************************************************************
        for (indiceCaseCourante = 0; indiceCaseCourante <= NB_LETTRES_PROP-1; indiceCaseCourante++)
            {
                nbOccurLetSBP[indiceCaseCourante] = 0;
                nbOccurLetS[indiceCaseCourante] = 0;
            }
        // *** () >> reinitialisationNbLettresBienEtMalPlacees > nbLettresBienPlacees, nbLettresMalPlacees *******************************************************************
        nbLettresBienPlacees = 0;
        nbLettresMalPlacees = 0;

    }
    

    // trouve >> finaliserPartie >> (écran) **********************************************************************************************************************************
    
    if(trouve){
        cout << "B R A V O : " << nbCoups << " tentatives pour trouver." << endl;
    }
    else{
        cout << "P E R D U : Vous avez perdu.";
    }


    return 0;
}