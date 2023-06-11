#include "readtype.h"
#include "Video.cpp"
#include "Movie.cpp"
#include "Series.cpp"
#include "Season.cpp"
#include "Episode.cpp"
#include <iostream>
#include <sstream>
#include <vector>

// It gives me the necessary tools to cause delays
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

    vector<int*> lengthSeries1;
    lengthSeries1.push_back(new int (23));
    lengthSeries1.push_back(new int (23));
    lengthSeries1.push_back(new int (24));
    lengthSeries1.push_back(new int (26));

    vector<int*> ratingsSeries1;
    ratingsSeries1.push_back(new int (5));
    ratingsSeries1.push_back(new int (5));
    ratingsSeries1.push_back(new int (2));
    ratingsSeries1.push_back(new int (3));


    dynamic_cast<Series*> (catalog.back())->setSeason("001","The Pool",idsSeries1,namesSeries1,lengthSeries1,ratingsSeries1);


    vector<string*> idsSeries2;
    idsSeries2.push_back(new string ("008"));
    idsSeries2.push_back(new string ("009"));
    idsSeries2.push_back(new string ("012"));
    idsSeries2.push_back(new string ("013"));

    vector<string*> namesSeries2;
    namesSeries2.push_back(new string ("PITU2"));
    namesSeries2.push_back(new string ("After the Caguama"));
    namesSeries2.push_back(new string ("When I wasn't old"));
    namesSeries2.push_back(new string ("When I wasn't old, the return of the young one"));

    vector<int*> lengthSeries2;
    lengthSeries2.push_back(new int (24));
    lengthSeries2.push_back(new int (23));
    lengthSeries2.push_back(new int (23));
    lengthSeries2.push_back(new int (23));

    vector<int*> ratingsSeries2;
    ratingsSeries2.push_back(new int (3));
    ratingsSeries2.push_back(new int (2));
    ratingsSeries2.push_back(new int (4));
    ratingsSeries2.push_back(new int (5));

    dynamic_cast<Series*> (catalog.back())->setSeason("002","The Floor is Lava",idsSeries2,namesSeries2,lengthSeries2,ratingsSeries2);


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
        << "\n2. Enter admin mode (It allows you to edit the titles inside the database)" << "\n3. Exit the app" << endl << endl;
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
        int titleNo;
        titleNo = ReadType<int>("Select the number of the title you wish to see: ");
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
        printf("\e[1;1H\e[2J");
        sleep_for(seconds(2));
        cout << "You have succesfully enter admin mode" << endl << endl;
        adminMenu(0,catalog);
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
        cout << "Available actions:" << "\n1. Watch the titles store in the system and edit them or delete them if you need to"
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
        int titleNo;
        titleNo = ReadType<int>("Select the number of the title you wish to edit (full info will be display): ");
        cout << endl;

        // Actions after editing
        if(titleNo >= 1 && titleNo <= catalog.size()){
            videoInfo(catalog, titleNo,true);
            sleep_for(seconds(2));
            
            cout << "Available actions: \n1. Edit store data (ID can't be changed) \n2. Delete it from the database"
            <<  "\n3. Go back to the main menu" << endl << endl;
            cout << "Select the number of the option you wish to perform: ";
            
            int choice = choiceValidation(1,3);
            if(choice == 1){
                editContent(catalog,titleNo);
            } else if(choice == 2){ // Make the options to delete content
                cout << "We are sorry for the inconvinience, our employees are severly underpaid "
                << "and weren't able to finish on time the option to delete content from the database. "
                << endl << "But hang in there, the option will come in a future.\nProbably...";
                sleep_for(seconds(6));
                adminMenu(0,catalog);
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
        break;
    case 2:
        cout << "We are sorry for the inconvinience, our employees are severly underpaid "
        << "and weren't able to finish on time the option to add content to the database. "
        << endl << "But hang in there, the option will come in a future.\nProbably...";
        sleep_for(seconds(6));
        adminMenu(0,catalog);
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

    cout << "\nSelect the number of what you wish to edit" << endl;
    int choice;

    if(Movie* movie = dynamic_cast<Movie*> (catalog[videoNumber - 1])){
        cout << "\n1. Title \n2. Length \n3. Genre \n4. Rating" << endl << endl;
        cout << "Option: ";
        choice = choiceValidation(1,4);
        cout << endl;
        if(choice == 1){
            string title;
            cout << "Write the title you wish to set: ";
            getline(cin >> ws,title);
            movie->setName(title);
        } else if(choice == 2){ 
            cout << "Select the number of the action you wish to do" << endl;
            int howToAddTime;
            
            cout << "\n1. Write the new length \n2. Add a certain amount of time"
            <<  "\n3. Reduce a certain amount of time" << endl << endl;
            
            cout << "Option: ";
            howToAddTime = choiceValidation(1,3);
            cout << endl;

            if(howToAddTime == 1){
                int length;
                length = ReadType<int>("Write the length you wish to set: ");
                movie->setLength(length);
                cout << endl;
            } else if(howToAddTime == 2){
                int extraTime;
                extraTime = ReadType<int>("Write the time you wish to add: ");
                *movie + extraTime;
                cout << endl;
            } else if(howToAddTime == 3){
                int reducedTime;
                reducedTime = ReadType<int>("Write the time you wish to reduce: ");
                *movie - reducedTime;
                cout << endl;
            }

        } else if(choice == 3){
            string genre;
            cout << "Write the genre you wish to set: ";
            getline(cin >> ws,genre);
            movie->setGenre(genre);
        } else if(choice == 4){
            cout << "Write the rating you wish to set (it must be between 1 to 5 stars): ";
            int rating = choiceValidation(1,5);
            movie->setRating(rating);
        }
        adminMenu(0,catalog);
    } else if(Series* series = dynamic_cast<Series*> (catalog[videoNumber - 1])){
        cout << "\n1. Series General Data \n2. Seasons" << endl << endl;
        cout << "Option: ";
        choice = choiceValidation(1,2);
        cout << endl;
        if(choice == 1){
            cout << "Select the number of what you wish to edit on the series: " << endl;
            cout << "\n1. Title \n2. Genre \n3. Overall Rating" << endl << endl;
            cout << "Option: ";
            int seriesEdition;
            seriesEdition = choiceValidation(1,3);
            cout << endl;
            if(seriesEdition == 1){
                string title;
                cout << "Write the title you wish to set for the series: ";
                getline(cin >> ws,title);
                series->setName(title);
            } else if (seriesEdition == 2){
                string genre;
                cout << "Write the genre you wish to set: ";
                getline(cin >> ws,genre);
                series->setGenre(genre);
            } else if (seriesEdition == 3){
                cout << "Write the rating you wish to set (it must be between 1 to 5 stars): ";
                int rating = choiceValidation(1,5);
                series->setRating(rating);
            }
            adminMenu(0,catalog);
        } else if (choice == 2){ // Write the code to edit the seasons and episodes

            cout << "Select the number of the season you wish to edit" << endl;
            for(int i = 0; i < series->getSeasons().size(); i++){ // Iterate through the seasons
                Season* season = series->getSeasons().at(i);
                cout << (i + 1) << ". " << season->getTitle() << endl;
            }
            cout << endl;
            cout << "Selected Season: ";
            int selectedSeason = choiceValidation(1,series->getSeasons().size());
            cout << endl;

            cout << "Select the number of what you wish to edit in the season: " << endl;
            cout << "\n1. Title \n2. Episodes" << endl << endl;
            cout << "Option: ";
            int seasonEdition;
            seasonEdition = choiceValidation(1,2);
            cout << endl;

            Season* season = series->getSeasons().at(selectedSeason - 1);

            if(seasonEdition == 1){
                string title;
                cout << "Write the title you wish to set for the season: ";
                getline(cin >> ws,title);
                season->setTitle(title);
            } else if(seasonEdition == 2){
                
                printf("\e[1;1H\e[2J");

                cout << "Select the number of the episode you wish to edit" << endl << endl;

                cout << "Episodes:" << endl;
                for(int j = 0; j < season->getEpisodes().size(); j++){ // Bucle for para obtener los episodios como punteros
                    Episode* episode = season->getEpisodes().at(j); // Saco los episodios del vector en la temporada
                    cout << (j + 1) << ". " << episode->getName() << endl;
                    cout << "Episode ID: " << episode->getId() << endl;
                    cout << "Length: " << episode->getLength() << " minutes" << endl;
                    cout << "Rating: " << episode->getRating() << " stars" << endl << endl;
                }

                sleep_for(seconds(8));
                cout << endl;
                cout << "Selected Episode: ";
                int selectedEpisode = choiceValidation(1,season->getEpisodes().size());
                cout << endl;

                cout << "Select the number of what you wish to edit in the episode: " << endl;
                cout << "\n1. Title \n2. Length \n3. Rating" << endl << endl;
                cout << "Option: ";
                int episodeEdition;
                episodeEdition = choiceValidation(1,3);
                cout << endl;
                Episode* episode = season->getEpisodes().at(selectedEpisode - 1);

                if(episodeEdition == 1){
                    string title;
                    cout << "Write the title you wish to set for the episode: ";
                    getline(cin >> ws,title);
                    episode->setName(title);
                } else if(episodeEdition == 2){
                    cout << "Select the number of the action you wish to do" << endl;
                    int howToAddTime;
                    
                    cout << "\n1. Write the new length \n2. Add a certain amount of time"
                    <<  "\n3. Reduce a certain amount of time" << endl << endl;
                    
                    cout << "Option: ";
                    howToAddTime = choiceValidation(1,3);
                    cout << endl;

                    if(howToAddTime == 1){
                        int length;
                        length = ReadType<int>("Write the length you wish to set: ");
                        movie->setLength(length);
                        cout << endl;
                    } else if(howToAddTime == 2){
                        int extraTime;
                        extraTime = ReadType<int>("Write the time you wish to add: ");
                        *episode + extraTime;
                        cout << endl;
                    } else if(howToAddTime == 3){
                        int reducedTime;
                        reducedTime = ReadType<int>("Write the time you wish to reduce: ");
                        *episode - reducedTime;
                        cout << endl;
                    }
                } else if(episodeEdition == 3){
                    cout << "Write the rating you wish to set (it must be between 1 to 5 stars): ";
                    int rating = choiceValidation(1,5);
                    episode->setRating(rating);
                }
                
                
            }
            adminMenu(0,catalog);
        }
        
    }


}

// A function to validate and return the choice made by the user
int choiceValidation(int lowerLimit, int upperLimit){
    int choice;
    choice = ReadType<int>("");
    while(choice < lowerLimit || choice > upperLimit){
        cout << "\nEnter a valid number for the action you wish to perform: ";
        choice = ReadType<int>("");;
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
        cout << "Length: " << movie->getLength() << " minutes" << endl;
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
            for(int j = 0; j < season->getEpisodes().size(); j++){ // Bucle for para obtener los episodios como punteros
                Episode* episode = season->getEpisodes().at(j); // Saco los episodios del vector en la temporada
                cout << (j + 1) << ". " << episode->getName() << endl;
                
                if(admin == true){
                    cout << "Episode ID: " << episode->getId() << endl;
                }

                cout << "Length: " << episode->getLength() << " minutes" << endl;
                cout << "Rating: " << episode->getRating() << " stars" << endl << endl;
            }
        }
    }

}