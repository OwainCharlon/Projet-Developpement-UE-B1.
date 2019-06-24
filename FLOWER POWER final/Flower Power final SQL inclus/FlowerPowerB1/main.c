#include "BDDlibtest.h"



int main(void)
{
    char* what = "*";
    char* where = "plante";
    int rowChosen = 15;
    char* resultatsReq = "";

    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    if(mysql_real_connect(&mysql,"localhost","root",NULL,"flowerpower",3306,NULL,0))
    {
        //Requ�te qui s�lectionne tout dans ma table plante
        char* reqBDD;
        reqBDD = concat(4, "SELECT ", what, " FROM ", where);
        mysql_query(&mysql, reqBDD);

        //D�claration des objets
        MYSQL_RES *result = NULL;
        MYSQL_ROW row;

        unsigned int i = 0;
        unsigned int num_champs = 0;

        //On met le jeu de r�sultat dans le pointeur result
        result = mysql_store_result(&mysql);

        //On choisit une ligne.
        mysql_data_seek(result, rowChosen);

        //On r�cup�re le nombre de champs
        num_champs = mysql_num_fields(result);

        //On stocke les valeurs de la ligne choisie.
        row = mysql_fetch_row(result);

        //On d�clare un pointeur long non sign� pour y stocker la taille des valeurs.
        unsigned long *lengths;

        //On stocke cette taille dans le pointeur.
        lengths = mysql_fetch_lengths(result);

        //On fait une boucle pour avoir la valeur de chaque champ.
        for(i = 0; i < num_champs; i++)
        {
            //On ecrit toutes les valeurs
            //printf("[%.*s] ", (int) lengths[i], row[i] ? row[i] : "NULL");
            //printf("\non fait un tour de for, avec row = %s\n", row[i]);
            if (i >= 1)
            {
                //printf("et on concat\n");
                resultatsReq = concatStr(resultatsReq, row[i]);
                resultatsReq = concatStr(resultatsReq, ":");
            }
        }

        printf("\nOn print resultatsReq\n");
        printf("%s\n", resultatsReq);
        //printf("\n On a print resultatsReq\n");

 // LA OU TOUT LE CODE S'EXECUTE

        char** resFinal;
        printf("\nEt on split :\n");
        resFinal = splitStr(resultatsReq, ":");

 // FIN DE LA OU TOUT S'EXECUTE

        //Lib�ration du jeu de r�sultat
        mysql_free_result(result);
        // Lib�ration de la m�moire allou�e a la requ�te
        free(reqBDD);

        //Fermeture de MySQL
        mysql_close(&mysql);

    }
    else
    {
        printf("Une erreur s'est produite lors de la connexion � la BDD!");
    }

        return 0;
}
