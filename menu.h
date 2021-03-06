#include "menuchoixplantes.h"

char mail[100];
char choix_user[20] = {0};

void ecran_acceuil()
{
    int testsave = 2;
    system("cls");
    system("COLOR E2");
    printf("%s","\n\n              BIENVENUE sur\n");
    printf("%s","               FLOWERPOWER\n\n\n");
    printf("%s","                 ..ooo.\n");
    printf("%s","               .888888888.\n");
    printf("%s","               88 P  T T888 8o\n");
    printf("%s","           o8o 8.8 8 88o. 8o 8o\n");
    printf("%s","          88 . o88o8 8 88. 8 88P o\n");
    printf("%s","         88 o8 88 oo.8 888 8 888 88\n");
    printf("%s","         88 88 88o888  88   o888 88\n");
    printf("%s","         88. 8o. T88P.88 . 88888 88\n");
    printf("%s","         888. 888. 88P .o8 8888 888\n");
    printf("%s","          888o 8888oo8888 o888 o8P \n");
    printf("%s","           8888.  888P P.888 .88P\n");
    printf("%s","            88888ooo  888P .o888\n");
    printf("%s","               8P  .oooooo8888P\n");
    printf("%s","  .oo888ooo.    888888888P8\n");
    printf("%s","  o88888 888 88o.   8888  .88   .oo888oo..\n");
    printf("%s","  8888   88 88888.       88 .o88888888 888.\n");
    printf("%s","   8888o.  o 88 88o.    o8 .888 888 88  88P\n");
    printf("%s","    T888C.oo.  8. 8 8   o8 o888 o88   .=888 \n");
    printf("%s","     88888888o  8 8 8  .8 .8 88 8  .o888o8P\n");
    printf("%s","       8888C.o8o  8 8  8  8 o  ...o   8888\n");
    printf("%s","         88888888   8 .8  8   88888888888\n");
    printf("%s","           8888888o  .8o=  o8o..o(8oo88\n");
    printf("%s","               888  88     888888888\n");
    printf("%s","                  o8P        888\n");
    printf("%s","                 88\n");
    Sleep(1000);
    testsave = verif_mail();
    if (testsave == 0)
        login();
    else if (testsave == 1)
        affiche_menu() ;

    return;
}

void affiche_menu ()
{
    system("cls");
    char choixuser;
    printf("%s", "\n\n   Menu :\n\n");
    printf("%s", "   1- Choix de votre Plante cherie que vous pourrez coucouner sans complications grace a FLOWER POWER\n\n");
    printf("%s", "   2- Premiers pas pour avoir les doigts verts !\n\n");
    printf("%s", "   3- A propos de FLOWER POWER\n\n");
    printf("%s", "   Entrez  votre choix suivi d'une pression sur la touche entree pour acceder a la page choisie.\n");
    while (choixuser != '1' && choixuser != '2' && choixuser != '3')
    {
        scanf("%c", &choixuser);
    }
    if (choixuser == '1')
        choix_plantes();
    else if (choixuser == '2')
        ppas();
    else if (choixuser == '3')
        apropros();
    return;
}

void login()
{
    system("cls");
    char* mail[100];
    printf("%s","\n\n\n   Entre ton mail :\n");
    scanf("%s", &mail);
    printf("%s","\n  Bien recu ! Tu seras notifie des besoins de ta plante a cette adresse ! Jettes-y un oeil regulierement !\n");
    save();
    affiche_menu();
}

void save()
{
    FILE *fic = fopen("save.txt", "w+");
    if(fic == NULL)
        exit(1);
    fprintf(fic, "%s", mail);
    fclose(fic);
}

void load()
{
    FILE *fic = fopen("save.txt", "r");
    if(fic == NULL)
        exit(1);
    fscanf(fic, "%s", &mail);
    fclose(fic);
}

int verif_mail ()
{
    FILE* fichier = NULL;
    int caractereActuel = 0;
    int compte_caract = 0;
    fichier = fopen("save.txt", "r");
    if (fichier != NULL)
    {
        // Boucle de lecture des caract�res un � un

        while (caractereActuel != EOF) // On continue tant que fgetc n'a pas retourn� EOF ()
        {
            caractereActuel = fgetc(fichier); // On lit le caract�re
            compte_caract ++;
        }
        fclose(fichier);
    }
    if (compte_caract <= 1)
        return 0;
    else if (compte_caract > 1)
        return 1;
}

void ppas ()
{
    system("cls");
    printf("%s", "\n\n      Si ce sont vos premiers pas en tant que jardinier (assiste electroniquement ou non),\n");
    printf("%s", "  ne  vous inquietez pas, nous allons vous donner la marche a suivre.\n");
    printf("%s", "  Tout d'abord, munissez vous de vos graines et de deux cotons demaquillants.\n");
    printf("%s", "  Il vous faut les imbiber d'eau et placer la graine entre les deux. Vous allez la faire\n");
    printf("%s", "  germer. Laissez la ainsi quelques jours jusqu'a ce que vous voyez le pedoncule apparaitre.\n\n");
    printf("%s", "  C'est le moment de la mettre en terre. Muni d'un pot, vous y mettrez des pierres ou\n");
    printf("%s", "  des billes d'argiles dans le fond pour drainer l'eau lors de l'arrosage. L� vous pourrez y\n");
    printf("%s", "  mettre la terre et mettre la graine a environ 1cm sous terre. Vous arroserez abondamment.\n");
    printf("%s", "  Une fois cela de fait, vous n'aurez plus qu'a vous laisser guider par FLOWER POWER pour l'entretien\n");
    printf("%s", "  de votre plante preferee !\n");
    printf("%s", "  A vos truelles ! C'est le moment de vous salir un peu les mains ! Aujourd'hui vous devenez\n");
    printf("%s", "  jardinier !\n\n\n");
    /*printf("%s", "  Appuyez sur Entree pour revenir au menu de depart.\n  ");*/
    Sleep(40000);
    affiche_menu();
}

void apropros ()
{
    system("cls");
    printf("%s", "\n\n      Ce projet a ete realise par Owain Charlon, Dylan Levraud et Paul Bagnis.\n");
    printf("%s", "  Dans le cadre de notre formation Ingesup au sein d'Ynov, nous avons eu comme\n");
    printf("%s", "  projet de realiser un programme qui a pour but d'assister un utilisateur dans\n");
    printf("%s", "  la plantation et l'entretien de plantes de notre region (Ile-de-France).\n");
    printf("%s", "  Avec FLOWER POWER, l'entretien de vos chere plantes ne sera plus un probleme:\n");
    printf("%s", "  notre programme vous notifiera tous les besoins de votre plante (exposition,\n");
    printf("%s", "  arrosage...). Ainsi vous pourrez aisement transformer un coin de chez vous en\n");
    printf("%s", "  jungle luxuriante !\n");
    printf("%s", "  Si vous avez des questions nous restons a votre disposition a l'adresse: \n");
    printf("%s", "  contact.flowerpower@gmail.com\n\n\n");
    printf("%s", "  Vous remerciant,\n");
    printf("%s", "  L'equipe de developpement,\n\n\n");
    /*printf("%s", "  Appuyez sur Entree pour revenir au menu de depart.\n  ");*/
    Sleep(40000);
    affiche_menu();
}

void choix_plantes()
{
    system("cls");
    char choixuser;
    choixuser = 'a';
    printf("%s", "\n\n   Souhaitez-vous:\n\n  1 - choisir dans notre base de donnee des plantes d'Ile-de-France.\n  2 - completer notre base avec un plante n'y figurant pas ?\n");
    printf("%s", "\n\n  Tapez le numero correspondant a votre choix suivi d'Entree.\n");
    while (choixuser != '1' && choixuser != '2')
        scanf("%c", &choixuser);
    if (choixuser == '1')
        menuchoixplantesbdd();
    else if (choixuser == '2')
        ajout_plante();
}

void ajout_plante()
{
    system("cls");
    char nom_plante[20] = {0};
    char besoin_eau[20] = {0};
    char besoin_soleil[20] = {0};
    char substrat[20] = {0};
    char besoin_ph[20] = {0};
    printf("%s", "\n\n          Bienvenue dans le mode d'ajout d'une plante a votre base de donnee.\n\n");
    printf("%s", "      Il vous faudra remplir les champs suivants : besoin en eau, en ensoleillement, quel\n  substrat utiliser (terre argileuse, sableuse etc...), et le ph ideal du substrat.\n\n");
    printf("%s", "      Prenons les choses a la base, et entrez le nom de votre plante (sans espaces, 20 caract�res maximum) :\n");
    scanf("%s", &nom_plante);
    printf("%s", "\n  Tres bien. Donnez nous son besoin en eau (note de 0 a 10):\n");
    scanf("%s", &besoin_eau);
    printf("%s", "\n  C'est note. Donnez nous maintenant son besoin en ensoleillement (note de 0 a 10):\n");
    scanf("%s", &besoin_soleil);
    printf("%s", "\n  Ok. Donnez nous maintenant le substrat dans lequelle elle pousse au mieux (donner \n  juste l'adjectif concernant la terre, ne mettez pas d'espaces):\n");
    scanf("%s", &substrat);
    printf("%s", "\n  Donnez nous maintenant le ph ideal de la terre (note de 0 a 14):\n");
    scanf("%s", &besoin_ph);
    printf("%s", "\n\n   Votre plante a ete enregistre, vous la retrouverez dans la liste suivante.\n");
    Sleep(3000);
    menuchoixplantesbdd();
}

