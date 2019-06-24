#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <mysql.h>



int main(void)
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    if(mysql_real_connect(&mysql,"localhost","root",NULL,"flowerpower",3306,NULL,0))
    {
        //Requête qui sélectionne tout dans ma table plante
        mysql_query(&mysql, "SELECT nom_plante FROM plante");
        //Déclaration des objets
        MYSQL_RES *result = NULL;
        MYSQL_ROW row;

        unsigned int i = 0;
        unsigned int num_champs = 0;

        //On met le jeu de résultat dans le pointeur result
        result = mysql_use_result(&mysql);

        //On choisit une ligne.
        mysql_data_seek(result, 4);

            //On récupère le nombre de champs
        num_champs = mysql_num_fields(result);

            //On stocke les valeurs de la ligne choisie.
        row = mysql_fetch_row(result);

            //On déclare un pointeur long non signé pour y stocker la taille des valeurs.
        unsigned long *lengths;

            //On stocke cette taille dans le pointeur.
        lengths = mysql_fetch_lengths(result);

            //On fait une boucle pour avoir la valeur de chaque champ.
        for(i = 0; i < num_champs; i++)
        {
                //On ecrit toutes les valeurs
            char* plante = ("%.*s ", (int) lengths[i], row[i] ? row[i] : "NULL");
            printf(plante);
        }

        //Libération du jeu de résultat
        mysql_free_result(result);

        //Fermeture de MySQL
        mysql_close(&mysql);
    }
    else
    {
        printf("Une erreur s'est produite lors de la connexion à la BDD!");
    }

    return 0;
}
