#include "bddplantes.h"

int verif_reponse(char* a, char* b)
{
    int i = 0;
    int comp = 0;
    while (i != 2)
    {
        if (a[i] == b[i])
            comp ++;
        i++;
    }
    if (comp == 2)
        return 1;
    else
        return 0;
}

void menuchoixplantesbdd()
{
    system("cls");
    char choix_user[2] = {0};
    printf("%s", "\n\n      Bienvenue dans la liste des plantes integrees a notre programme,\n  veuillez en choisir une dans la liste suivante en tapant son numero suivi d'Entree.\n   Vous obtiendrez ainsi toutes les informations la concernant, a vous de jouer !\n\n");
    printf("%s", "\n    01- Viorne Lantane\n    02- Sureau Noir\n    03- Saule Pourpre\n    04- Saule a Oreille\n    05- Saule Blanc\n    06- Ronce Bleue\n    07- Rosier Pimprenelle\n    08- Rosier des Champs\n    09- Bourdaine\n    10- Lierre Grimpant\n    11- Noisetier\n    12- Buis\n    13- Erable\n    14- Achillee Sternutatoire\n    15- Bugle Rampante\n    16- Ail Jaune\n    17- Guimauve\n    18- Anemone\n    19- Fougere Femelle\n    20- Paquerette\n    21- Amourette\n    22- Populage\n    23- Muguet\n    24- Digitale Pourpre\n    25- Fougere Male\n    26- Reine des Pres\n    27- Asperule Odorante\n    28- Lierre Terrestre\n    29- Houblon\n    30- Iris Faux Acore\n    99- Retour\n\n");
    scanf("%s", &choix_user);
    if (verif_reponse(choix_user, "01") == 1)
        viornelantane();
    else if (verif_reponse(choix_user, "02") == 1)
        sureaunoir();
    else if (verif_reponse(choix_user, "03") == 1)
        saulepourpre();
    else if (verif_reponse(choix_user, "04") == 1)
        sauleaoreille();
    else if (verif_reponse(choix_user, "05") == 1)
        sauleblanc();
    else if (verif_reponse(choix_user, "06") == 1)
        roncebleu();
    else if (verif_reponse(choix_user, "07") == 1)
        rosierpimprenelle();
    else if (verif_reponse(choix_user, "08") == 1)
        rosierdeschamps();
    else if (verif_reponse(choix_user, "09") == 1)
        bourdaine();
    else if (verif_reponse(choix_user, "10") == 1)
        lierregrimp();
    else if (verif_reponse(choix_user, "11") == 1)
        noisetier();
    else if (verif_reponse(choix_user, "12") == 1)
        buis();
    else if (verif_reponse(choix_user, "13") == 1)
        erable();
    else if (verif_reponse(choix_user, "14") == 1)
        Achilleesternutatoire();
    else if (verif_reponse(choix_user, "15") == 1)
        buglerampante();
    else if (verif_reponse(choix_user, "16") == 1)
        ailjaune();
    else if (verif_reponse(choix_user, "17") == 1)
        guimauve();
    else if (verif_reponse(choix_user, "18") == 1)
        anemone();
    else if (verif_reponse(choix_user, "19") == 1)
        fougere();
    else if (verif_reponse(choix_user, "20") == 1)
        paquerette();
    else if (verif_reponse(choix_user, "21") == 1)
        amourette();
    else if (verif_reponse(choix_user, "22") == 1)
        populage();
    else if (verif_reponse(choix_user, "23") == 1)
        muguet();
    else if (verif_reponse(choix_user, "24") == 1)
        digitalepourpre();
    else if (verif_reponse(choix_user, "25") == 1)
        fougeremale();
    else if (verif_reponse(choix_user, "26") == 1)
        reinedespres();
    else if (verif_reponse(choix_user, "27") == 1)
        asperuleodorante();
    else if (verif_reponse(choix_user, "28") == 1)
        lierreterrestre();
    else if (verif_reponse(choix_user, "29") == 1)
        houblon();
    else if (verif_reponse(choix_user, "30") == 1)
        irisfauxacore();
    else if (verif_reponse(choix_user, "99") == 1)
        choix_plantes();
}
