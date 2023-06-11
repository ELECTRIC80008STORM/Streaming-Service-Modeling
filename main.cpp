#include "readtype.h"
#include "Video.cpp"
#include "Movie.cpp"
#include "Series.cpp"
#include "Season.cpp"
#include "Episode.cpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

// Declaration of functions
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
    sleep_for(seconds(3));
    userMenu(0,catalog);

    return 0;
}

/**
 * Displays a user menu based on the given choice and performs corresponding actions.
 * @param int choice: the user's menu choice
 * const vector<Video*>& catalog: a reference to the video catalog
 * @return
*/
void userMenu(int choice, const vector<Video*> &catalog){
    switch (choice)
    {
    case 0:
        cout << "Available actions:" << "\n1. Watch the titles that are trending now"
        << "\n2. Enter admin mode (It allows you to edit the titles inside the database)" << "\n3. Exit the app" << endl << endl;
        cout << "Select the number of the option you wish to perform: ";
        userMenu(choiceValidation(1,3),catalog);
        break;

    case 1:
        printf("\e[1;1H\e[2J");
        cout << "Trending Now:" << endl << endl;
        sleep_for(seconds(2));

        for(int i = 0; i < catalog.size(); i++){
            cout << (i + 1) << ". " << catalog[i]->getName() << endl;
        }

        cout << endl;

        int titleNumber;
        titleNumber = ReadType<int>("Select the number of the title you wish to see: ");
        cout << endl;

        if(titleNumber >= 1 && titleNumber <= catalog.size()){
            videoInfo(catalog, titleNumber,false);
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
        } else{
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

/**
 * Displays an admin menu based on the given choice and performs corresponding actions.
 * @param int choice: the admin's menu choice
 * const vector<Video*>& catalog: a reference to the video catalog
 * @return
*/
void adminMenu(int choice, const vector<Video*>& catalog){
    switch (choice)
    {
    case 0:
        cout << "Available actions:" << "\n1. Watch the titles store in the system and edit them or delete them if you need to"
        << "\n2. Add content to the database" << "\n3. Exit admin mode" << "\n4. Exit the app" << endl << endl;
        cout << "Select the number of the option you wish to perform: ";
        adminMenu(choiceValidation(1,4),catalog);
        break;

    case 1:
        printf("\e[1;1H\e[2J");
        cout << "Titles:" << endl << endl;
        sleep_for(seconds(2));

        for(int i = 0; i < catalog.size(); i++){
            cout << (i + 1) << ". " << catalog[i]->getName() << endl;
        }

        cout << endl;

        int titleNumber;
        titleNumber = ReadType<int>("Select the number of the title you wish to edit (full info will be display): ");
        cout << endl;

        if(titleNumber >= 1 && titleNumber <= catalog.size()){
            videoInfo(catalog, titleNumber,true);
            sleep_for(seconds(2));
            
            cout << "Available actions: \n1. Edit store data (ID can't be changed) \n2. Delete it from the database"
            <<  "\n3. Go back to the main menu" << endl << endl;
            cout << "Select the number of the option you wish to perform: ";
            
            int choice = choiceValidation(1,3);

            if(choice == 1){
                editContent(catalog,titleNumber);
            } else if(choice == 2){
                cout << "\nWe are sorry for the inconvinience, our employees are severly underpaid "
                << "and weren't able to finish on time the option to delete content from the database. "
                << endl << "But hang in there, the option will come in a future.\nProbably...";

                sleep_for(seconds(6));
                adminMenu(0,catalog);
            } else if(choice == 3){
                printf("\e[1;1H\e[2J");
                adminMenu(0,catalog);    
            }
        } else{
            cout << "Remember, the number must be one of the ones that are next to the titles\n";
            sleep_for(seconds(6));
            printf("\e[1;1H\e[2J");
            userMenu(1,catalog);
        }
        break;

    case 2:
        cout << "\nWe are sorry for the inconvinience, our employees are severly underpaid "
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

/**
 * Edits the content of a video in the catalog.
 * @param catalog The vector of Video pointers representing the catalog
 * videoNumber The number of the video to edit
 * @return
*/
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
            int timeOption;
            
            cout << "\n1. Write the new length \n2. Add a certain amount of time"
            <<  "\n3. Reduce a certain amount of time" << endl << endl;
            
            cout << "Option: ";
            timeOption = choiceValidation(1,3);
            cout << endl;

            if(timeOption == 1){
                int length;
                length = ReadType<int>("Write the length you wish to set: ");
                movie->setLength(length);
                cout << endl;
            } else if(timeOption == 2){
                int extraTime;
                extraTime = ReadType<int>("Write the time you wish to add: ");
                *movie + extraTime;
                cout << endl;
            } else if(timeOption == 3){
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
        } else if (choice == 2){

            cout << "Select the number of the season you wish to edit" << endl;

            for(int i = 0; i < series->getSeasons().size(); i++){
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
                for(int j = 0; j < season->getEpisodes().size(); j++){
                    Episode* episode = season->getEpisodes().at(j);
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
                    int timeOption;
                    
                    cout << "\n1. Write the new length \n2. Add a certain amount of time"
                    <<  "\n3. Reduce a certain amount of time" << endl << endl;
                    
                    cout << "Option: ";
                    timeOption = choiceValidation(1,3);
                    cout << endl;

                    if(timeOption == 1){
                        int length;
                        length = ReadType<int>("Write the length you wish to set: ");
                        movie->setLength(length);
                        cout << endl;
                    } else if(timeOption == 2){
                        int extraTime;
                        extraTime = ReadType<int>("Write the time you wish to add: ");
                        *episode + extraTime;
                        cout << endl;
                    } else if(timeOption == 3){
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

/**
 * Validates the user's choice within a specified range.
 * @param lowerLimit The lower limit of the valid range
 * upperLimit The upper limit of the valid range
 * @return The validated choice within the specified range
*/
int choiceValidation(int lowerLimit, int upperLimit){
    int choice;
    choice = ReadType<int>("");

    while(choice < lowerLimit || choice > upperLimit){
        cout << "\nEnter a valid number for the action you wish to perform: ";
        choice = ReadType<int>("");;
    }

    return choice;
}

/**
 * Displays information about a video.
 * @param catalog The vector of Video pointers representing the catalog
 * videoNumber The index of the video to display information for
 * admin Indicates whether the user is an admin or not
 * @return
*/
void videoInfo(const vector<Video*> &catalog, int videoNumber, bool admin){
    
    sleep_for(seconds(2));
    cout << catalog[videoNumber - 1]->getName() << endl;

    if(admin == true){
        cout << "ID: " << catalog[videoNumber - 1]->getId() << endl;
    }

    Series* series = dynamic_cast<Series*> (catalog[videoNumber - 1]);
    
    if(Movie* movie = dynamic_cast<Movie*> (catalog[videoNumber - 1])){
        cout << "Length: " << movie->getLength() << " minutes" << endl;
    } else if(series != nullptr){
        if(series->getSeasons().size() == 1){
            cout << "Number of seasons: " << series->getSeasons().size() << " season" << endl;
        } else{
            cout << "Number of seasons: " << series->getSeasons().size() << " seasons" << endl;
        }
        
    } else{cout << "Unknown Type" << endl;}

    cout << "Genre: " << catalog[videoNumber - 1]->getGenre() << endl;
    cout << "Rating: " << catalog[videoNumber - 1]->getRating() << " stars" << endl << endl;

    if(series != nullptr){
        for(int i = 0; i < series->getSeasons().size(); i++){
            Season* season = series->getSeasons().at(i); 
            cout << "Season " << (i + 1) << ": " << season->getTitle() << endl;
            
            if(admin == true){
                cout << "Season ID: " << season->getId() << endl << endl;
            }

            cout << "Episodes:" << endl;
            for(int j = 0; j < season->getEpisodes().size(); j++){
                Episode* episode = season->getEpisodes().at(j);
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
