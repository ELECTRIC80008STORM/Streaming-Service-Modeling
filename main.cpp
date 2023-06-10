#include "Video.cpp"
#include "Movie.cpp"
#include "Series.cpp"
#include "Season.cpp"
#include "Episode.cpp"
#include <iostream>
#include <sstream>
#include <vector>

// Researched on internet
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

void userMenu(int, const vector<Video*>&);
void adminMenu(int, const vector<Video*>&);
int choiceValidation(int, int);
void videoInfo(const vector<Video*>&, int, bool);
void editContent(const vector<Video*>&, int);

int main(){

    vector<Video*> catalog;
    
    // Movies
    catalog.push_back(new Movie("000", "Spider-Man: Into the Spider-Verse", 120, "Action, Superheroes",5));
    string movie2[1] = {"Superhero"};
    catalog.push_back(new Movie("001", "Guardians of the Galaxy Vol. 3", 149, "Action, Superheroes",5));
    string movie3[2] = {"Terror","Gore"};
    catalog.push_back(new Movie("002", "The Boogeyman", 98, "Horror, Gore",3));
    string movie4[3] = {"Musical","Fantasy", "Live Action"};
    catalog.push_back(new Movie("003", "The Little Mermaid", 136, "For Kids, Fantasy",4));
    string movie5[2] = {"Action", "Spies"};
    catalog.push_back(new Movie("004", "Fast X", 141, "Action, Spies, Heists",3));

    // Series
    catalog.push_back(new Series("007","Adventures of James Bond's Child",69,"Action, Spies, For Kids", 7));

    vector<string*> idsSeries1;
    idsSeries1.push_back(new string ("002"));
    idsSeries1.push_back(new string ("003"));
    idsSeries1.push_back(new string ("004"));
    idsSeries1.push_back(new string ("005"));

    vector<string*> namesSeries1;
    namesSeries1.push_back(new string ("P1"));
    namesSeries1.push_back(new string ("After the Martinni"));
    namesSeries1.push_back(new string ("When I was young"));
    namesSeries1.push_back(new string ("When I was young 2"));

    vector<int*> lenghtSeries1;
    lenghtSeries1.push_back(new int (23));
    lenghtSeries1.push_back(new int (23));
    lenghtSeries1.push_back(new int (24));
    lenghtSeries1.push_back(new int (26));

    vector<int*> ratingsSeries1;
    ratingsSeries1.push_back(new int (23));
    ratingsSeries1.push_back(new int (23));
    ratingsSeries1.push_back(new int (24));
    ratingsSeries1.push_back(new int (26));


    dynamic_cast<Series*> (catalog.back())->setSeason("001","The Pool",idsSeries1,namesSeries1,lenghtSeries1,ratingsSeries1);

    printf("\e[1;1H\e[2J");
    cout << "StreamingWave\n\n";
    // sleep_for(seconds(3));
    // userMenu(0,catalog);
    adminMenu(0,catalog);

    
    // cout << "Catalog Size: " << catalog.size();
    // videoInfo(catalog,6,false);

    return 0;
}

// Función que provee el menú para los usuarios
void userMenu(int choice, const vector<Video*> &catalog){
    switch (choice)
    {
    case 0: // Menu Principal Usuarios
        cout << "Available actions:" << "\n1. Watch the titles that are trending now"
        << "\n2. Enter as admin (It allows you to edit the titles inside the database)" << "\n3. Exit the app" << endl << endl;
        cout << "Select the number of the option you wish to perform: ";
        userMenu(choiceValidation(1,3),catalog);
        break;
    case 1: // Catálogo completo sin mostrar ID, permite al usuario seleccionar que título desea ver en específico
        printf("\e[1;1H\e[2J");
        cout << "Trending Now:" << endl << endl;
        // sleep_for(seconds(2));
        for(int i = 0; i < catalog.size(); i++){
            cout << (i + 1) << ". " << catalog[i]->getName() << endl;
        }
        cout << endl;
        // sleep_for(seconds(2));
        cout << "Select the number of the title you wish to see: ";
        int titleNo;
        cin >> titleNo;
        cout << endl;

        // Actions
        if(titleNo >= 1 && titleNo <= catalog.size()){
            videoInfo(catalog, titleNo,false);
            sleep_for(seconds(2));
            cout << "Available actions: \n1. Go back to the menu \n2. Exit the app" << endl << endl;
            cout << "Select the number of the option you wish to perform: ";
            int choice = choiceValidation(1,2);
            if(choice == 1){
                printf("\e[1;1H\e[2J");
                userMenu(0,catalog);    
            } else if(choice == 2){
                userMenu(3,catalog);
            }
        } 
        else{
            cout << "Remember, the number must be one of the ones that are next to the titles\n";
            sleep_for(seconds(6));
            printf("\e[1;1H\e[2J");
            userMenu(1,catalog);
        }
        break;
    case 2:
        cout << "Admin Mode" << endl << endl;
        // adminMenu(0,catalog);
        // sleep_for(seconds(2));
        break;
    case 3:
        printf("\e[1;1H\e[2J");
        cout << "You have exit the app" << endl;
        break;
    default:
        break;
    }
}

// Función que provee el menú para los administradores
void adminMenu(int choice, const vector<Video*>& catalog){
    switch (choice)
    {
    case 0: // Menu Principal Administrador
        cout << "Available actions:" << "\n1. Watch the titles store in the system and edit them if you need to"
        << "\n2. Add content to the database" << "\n3. Exit admin mode" << "\n4. Exit the app" << endl << endl;
        cout << "Select the number of the option you wish to perform: ";
        adminMenu(choiceValidation(1,4),catalog);
        break;
    case 1: // Catálogo completo, permite al administrador seleccionar que título desea ver en específico
        printf("\e[1;1H\e[2J");
        cout << "Titles:" << endl << endl;
        // sleep_for(seconds(2));
        for(int i = 0; i < catalog.size(); i++){
            cout << (i + 1) << ". " << catalog[i]->getName() << endl;
        }
        cout << endl;
        // sleep_for(seconds(2));
        cout << "Select the number of the title you wish to edit (full info will be display): ";
        int titleNo;
        cin >> titleNo;
        cout << endl;

        // Actions after editing
        if(titleNo >= 1 && titleNo <= catalog.size()){
            videoInfo(catalog, titleNo,true);
            sleep_for(seconds(2));
            
            // TO DO: Set the right actions
            cout << "Available actions: \n1. Edit store data (ID can't be changed) \n2. Delete it from the database"
            <<  "\n3. Go back to the main menu" << endl << endl;
            cout << "Select the number of the option you wish to perform: ";
            
            int choice = choiceValidation(1,3);
            if(choice == 1){
                editContent(catalog,titleNo);
            } else if(choice == 2){

            } else if(choice == 3){
                printf("\e[1;1H\e[2J");
                adminMenu(0,catalog);    
            } else{

            }
        
        } else{
            cout << "Remember, the number must be one of the ones that are next to the titles\n";
            sleep_for(seconds(6));
            printf("\e[1;1H\e[2J");
            userMenu(1,catalog);
        }

        // cout << "Available actions: \n1. Go back to the admin menu \n2. Exit the app" << endl << endl;
        // cout << "Select the number of the option you wish to perform: ";
        // int choice = choiceValidation(1,2);
        // if(choice == 2){
        //     userMenu(3,catalog);    
        // } else{
        //     userMenu(choice,catalog);
        // }
        break;
    case 2:

        break;
    case 3:
        printf("\e[1;1H\e[2J");
        sleep_for(seconds(2));
        cout << "You have succesfully exit admin mode, you're now in user mode" << endl << endl;
        userMenu(0,catalog);
        break;
    case 4:
        printf("\e[1;1H\e[2J");
        cout << "You have exit the app" << endl;
        break;
    default:
        break;
    }
}

//A function made to facilitate the process of adding content
void editContent(const vector<Video*>& catalog, int videoNumber){
    sleep_for(seconds(2));
    printf("\e[1;1H\e[2J");
    videoInfo(catalog, videoNumber,true);

    cout << "\nSelect the number of what you wish to edit (write 0 if you wish to return to the menu)" << endl;
    int choice;

    if(Movie* movie = dynamic_cast<Movie*> (catalog[videoNumber - 1])){
        cout << "\n1. Title \n2. Lenght \n3. Genre \n4. Rating" << endl << endl;
        cout << "Selection: ";
        choice = choiceValidation(0,4);
        cout << endl;
        if(choice == 1){
            string title;
            cout << "Write the title you wish to set: " << endl << endl;
            cin >> title; // Necesitara ser cambiado para evitar el error de poner más de una palabra
            movie->setName(title);
        } else if(choice == 2){ // TO DO: Add the operator overload
            int lenght;
            cout << "Write the lenght you wish to set: " << endl << endl;
            cin >> lenght; // Necesitara ser cambiado para evitar el error de poner más de una palabra
            movie->setLenght(lenght);
        } else if(choice == 3){
            string genre;
            cout << "Write the genre you wish to set: " << endl << endl;
            cin >> genre; // Necesitara ser cambiado para evitar el error de poner más de una palabra
            movie->setGenre(genre);
        } else if(choice == 4){
            int rating;
            cout << "Write the rating you wish to set: " << endl << endl;
            cin >> rating; // Necesitara ser cambiado para evitar el error de poner más de una palabra
            movie->setRating(rating);
        }
        adminMenu(0,catalog);
    } else if(Series* series = dynamic_cast<Series*> (catalog[videoNumber - 1])){

    }


}

// A function to valide and return the choice made by the user
int choiceValidation(int lowerLimit, int upperLimit){
    int choice;
    cin >> choice;
    while(choice < lowerLimit || choice > upperLimit){
        cout << "\nEnter a valid number for the action you wish to perform: ";
        cin >> choice;
    }
    return choice;
}

// Función para facilitar el mostrar todo el contenido de las películas y vídeos
void videoInfo(const vector<Video*> &catalog, int videoNumber, bool admin){
    
    // sleep_for(seconds(2));
    cout << catalog[videoNumber - 1]->getName() << endl;

    if(admin == true){
        cout << "ID: " << catalog[videoNumber - 1]->getId() << endl;
    }

    Series* series = dynamic_cast<Series*> (catalog[videoNumber - 1]); // Dynamic casting para convertir el puntero vídeo a serie
    
    // Condicional para permitir mostrar de manera distinta la duración dependiendo de sí es una película o serie
    if(Movie* movie = dynamic_cast<Movie*> (catalog[videoNumber - 1])){
        cout << "Lenght: " << movie->getLenght() << " minutes" << endl;
    } else if(series != nullptr){
        if(series->getSeasons().size() == 1){
            cout << "Number of seasons: " << series->getSeasons().size() << " season" << endl;
        } else{
            cout << "Number of seasons: " << series->getSeasons().size() << " seasons" << endl;
        }
        
    } else{cout << "Unknown Type" << endl;} // TO DO: Turn in to an error warning

    cout << "Genre: " << catalog[videoNumber - 1]->getGenre() << endl;
    cout << "Rating: " << catalog[videoNumber - 1]->getRating() << " stars" << endl << endl;

    // Condicional para iterar los atributos de la serie y poder mostrar las temporadas y episodios
    if(series != nullptr){
        for(int i = 0; i < series->getSeasons().size(); i++){ //  Bucle for para obtener las temporadas como punteros
            Season* season = series->getSeasons().at(i); // Saco las temporadas del vector en la serie
            cout << "Season " << (i + 1) << ": " << season->getTitle() << endl;
            
            if(admin == true){
                cout << "Season ID: " << season->getId() << endl << endl;
            }

            cout << "Episodes:" << endl;
            for(int i = 0; i < season->getEpisodes().size(); i++){ // Bucle for para obtener los episodios como punteros
                Episode* episode = season->getEpisodes().at(i); // Saco los episodios del vector en la temporada
                cout << (i + 1) << ". " << episode->getName() << endl;
                
                if(admin == true){
                    cout << "Episode ID: " << episode->getId() << endl;
                }

                cout << "Lenght: " << episode->getLenght() << " minutes" << endl;
                cout << "Rating: " << episode->getRating() << " stars" << endl << endl;
                delete(episode); // Borra el puntero de episodio que creo con cada iteración
            }
        }
    }

}