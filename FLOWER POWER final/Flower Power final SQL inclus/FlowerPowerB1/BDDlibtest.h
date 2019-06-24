#include <winsock.h>
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>       // calloc
#include <stdarg.h>       // va_*
#include <string.h>       // strlen, strcpy

// Merci StackOverflow : https://stackoverflow.com/questions/8465006/how-do-i-concatenate-two-strings-in-c/8465083
char* concat(int count, ...)
{
    va_list ap;
    int i;

    // Find required length to store merged string
    int len = 1; // room for NULL
    va_start(ap, count);
    for(i=0 ; i<count ; i++)
        len += strlen(va_arg(ap, char*));
    va_end(ap);

    // Allocate memory to concat strings
    char *merged = calloc(sizeof(char),len);
    int null_pos = 0;

    // Actually concatenate strings
    va_start(ap, count);
    for(i=0 ; i<count ; i++)
    {
        char *s = va_arg(ap, char*);
        strcpy(merged+null_pos, s);
        null_pos += strlen(s);
    }
    va_end(ap);

    return merged;
}

char* concatStr(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

char** splitStr(char* str, char c)
{
    // PAS FINI !!!!
    // L'idée étant de diviser la chaine obtenue suite à la requête SQL dans un tableau 2D pour ensuite pouvoir utilisé chacun des éléments.
    char* res[4];
    int i = 0;
    int j = 0;
    char* temp;
    printf("%s\n", str);
    while(j < 4)
    {
        printf("je suis dans le premier while");
        while(i < strlen(str))
        {
            printf("Je suis dans le deuxieme while");
            if(str[i] == ":")
            {
                break;
            }
            temp[i] = strcpy(temp[i], str[i]);
            i++;
        }
        temp[i + 1] = strcpy(temp[i + 1], "\0");
        printf("%s\n", temp);
        res[j] = concatStr(res[j], temp);
        j++;
        i++;
    }
    return res;
}


char* selectnRowBDD(char* what, char* where, int rowChosen)
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    char* resultatsReq;
    //printf("\n On print resultatsReq\n");
    //printf("%s", resultatsReq);
    //printf("\n On a print resultatsReq\n");

    if(mysql_real_connect(&mysql,"localhost","root",NULL,"flowerpower",3306,NULL,0))
    {
        //Requête qui sélectionne tout dans ma table plante
        char* reqBDD;
        reqBDD = concat(4, "SELECT ", what, " FROM ", where);
        mysql_query(&mysql, reqBDD);

        //Déclaration des objets
        MYSQL_RES *result = NULL;
        MYSQL_ROW row;

        unsigned int i = 0;
        unsigned int num_champs = 0;

        //On met le jeu de résultat dans le pointeur result
        result = mysql_store_result(&mysql);

        //On choisit une ligne.
        mysql_data_seek(result, rowChosen);

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
            printf("[%.*s] ", (int) lengths[i], row[i] ? row[i] : "NULL");
            printf("\non fait un tour de for, avec row = %s\n", row[i]);
            if (i >= 1)
            {
                printf("et on concat\n");
                resultatsReq = strcat(resultatsReq, ":");
                resultatsReq = strcat(resultatsReq, row[i]) ;
            }
        }

        printf("\n On print resultatsReq\n");
        printf("%s", resultatsReq);
        printf("\n On a print resultatsReq\n");

        //Libération du jeu de résultat
        mysql_free_result(result);
        // Libération de la mémoire allouée a la requête
        free(reqBDD);

        //Fermeture de MySQL
        mysql_close(&mysql);

    }
    else
    {
        printf("Une erreur s'est produite lors de la connexion à la BDD!");
    }

    return 0;
}

char* selectRowBDD(char* what, char* where)
{
    //Déclaration du pointeur de structure de type MYSQL
    MYSQL mysql;
    //Initialisation de MySQL
    mysql_init(&mysql);
    //Options de connexion
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    //Si la connexion réussie...
    if(mysql_real_connect(&mysql,"localhost","root",NULL,"flowerpower",3306,NULL,0))
    {
        //Requête qui sélectionne tout dans ma table scores
        char* reqBDD;
        reqBDD = concat(4, "SELECT ", what, " FROM ", where);
        printf(reqBDD);
        mysql_query(&mysql, reqBDD);

        //Déclaration des objets
        MYSQL_RES *result = NULL;
        MYSQL_ROW row;

        unsigned int i = 0;
        unsigned int num_champs = 0;

        //On met le jeu de résultat dans le pointeur result
        result = mysql_use_result(&mysql);
        printf("\nOn print result : \n");
        printf(result);
        printf("\n on a print result\n");

        //On récupère le nombre de champs
        num_champs = mysql_num_fields(result);
        printf("\nOn print num_champs : \n");
        printf("%d", num_champs);
        printf("\n on a print num_champs\n");

        //Tant qu'il y a encore un résultat ...
        while ((row = mysql_fetch_row(result)))
        {
            //On déclare un pointeur long non signé pour y stocker la taille des valeurs
            unsigned long *lengths;

            //On stocke ces tailles dans le pointeur
            lengths = mysql_fetch_lengths(result);
            // printf(lengths); ==> print des point d'interrogation

            //On fait une boucle pour avoir la valeur de chaque champs
            for(i = 0; i < num_champs; i++)
            {
               //On ecrit toutes les valeurs
               printf("[%.*s] ", (int) lengths[i], row[i] ? row[i] : "NULL");
            }
            printf("\n");
        }

        //Libération du jeu de résultat
        mysql_free_result(result);

        //Fermeture de MySQL
        mysql_close(&mysql);

    }
    else  //Sinon ...
    {
        printf("Une erreur s'est produite lors de la connexion à la BDD!");
    }

    return 0;
}
