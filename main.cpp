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
    catalog.push_back(new Series("005","Demon Slayer: Kimetsu no Yaiba",3,"Anime, Adventure, Dark Fantasy, Martial Arts", 5));

    vector<string*> idsSeason1DemonSlayer;
    idsSeason1DemonSlayer.push_back(new string ("000"));
    idsSeason1DemonSlayer.push_back(new string ("001"));
    idsSeason1DemonSlayer.push_back(new string ("002"));
    idsSeason1DemonSlayer.push_back(new string ("003"));
    idsSeason1DemonSlayer.push_back(new string ("004"));
    idsSeason1DemonSlayer.push_back(new string ("005"));
    idsSeason1DemonSlayer.push_back(new string ("006"));
    idsSeason1DemonSlayer.push_back(new string ("007"));
    idsSeason1DemonSlayer.push_back(new string ("008"));
    idsSeason1DemonSlayer.push_back(new string ("009"));
    idsSeason1DemonSlayer.push_back(new string ("010"));
    idsSeason1DemonSlayer.push_back(new string ("011"));
    idsSeason1DemonSlayer.push_back(new string ("012"));
    idsSeason1DemonSlayer.push_back(new string ("013"));
    idsSeason1DemonSlayer.push_back(new string ("014"));
    idsSeason1DemonSlayer.push_back(new string ("015"));
    idsSeason1DemonSlayer.push_back(new string ("016"));
    idsSeason1DemonSlayer.push_back(new string ("017"));
    idsSeason1DemonSlayer.push_back(new string ("018"));
    idsSeason1DemonSlayer.push_back(new string ("019"));
    idsSeason1DemonSlayer.push_back(new string ("020"));
    idsSeason1DemonSlayer.push_back(new string ("021"));
    idsSeason1DemonSlayer.push_back(new string ("022"));
    idsSeason1DemonSlayer.push_back(new string ("023"));
    idsSeason1DemonSlayer.push_back(new string ("024"));
    idsSeason1DemonSlayer.push_back(new string ("025"));

    vector<string*> namesSeason1DemonSlayer;
    namesSeason1DemonSlayer.push_back(new string ("Cruelty"));
    namesSeason1DemonSlayer.push_back(new string ("Trainer Sakonji Urokodaki"));
    namesSeason1DemonSlayer.push_back(new string ("Sabito and Makomo"));
    namesSeason1DemonSlayer.push_back(new string ("Final Selection"));
    namesSeason1DemonSlayer.push_back(new string ("My Own Steel"));
    namesSeason1DemonSlayer.push_back(new string ("Swordsman Accompanying a Demon"));
    namesSeason1DemonSlayer.push_back(new string ("Muzan Kibutsuji"));
    namesSeason1DemonSlayer.push_back(new string ("The Smell of Enchanting Blood"));
    namesSeason1DemonSlayer.push_back(new string ("Temari Demon and Arrow Demon"));
    namesSeason1DemonSlayer.push_back(new string ("Together Forever"));
    namesSeason1DemonSlayer.push_back(new string ("Tsuzumi Mansion"));
    namesSeason1DemonSlayer.push_back(new string ("The Boar Bares Its Fangs, Zenitsu Sleeps"));
    namesSeason1DemonSlayer.push_back(new string ("Something More Important Than Life"));
    namesSeason1DemonSlayer.push_back(new string ("The House with the Wisteria Family Crest"));
    namesSeason1DemonSlayer.push_back(new string ("Mount Natagumo"));
    namesSeason1DemonSlayer.push_back(new string ("Letting Someone Else Go First"));
    namesSeason1DemonSlayer.push_back(new string ("You Must Master a Single Thing"));
    namesSeason1DemonSlayer.push_back(new string ("A Forged Bond"));
    namesSeason1DemonSlayer.push_back(new string ("Hinokami"));
    namesSeason1DemonSlayer.push_back(new string ("Pretend Family"));
    namesSeason1DemonSlayer.push_back(new string ("Against Corps Rules"));
    namesSeason1DemonSlayer.push_back(new string ("Master of the Mansion"));
    namesSeason1DemonSlayer.push_back(new string ("Hashira Meeting"));
    namesSeason1DemonSlayer.push_back(new string ("Rehabilitation Training"));
    namesSeason1DemonSlayer.push_back(new string ("Tsuguko, Kanao Tsuyuri"));
    namesSeason1DemonSlayer.push_back(new string ("New Mission"));


    vector<int*> lengthSeason1DemonSlayer;
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (23));
    lengthSeason1DemonSlayer.push_back(new int (24));

    vector<int*> ratingsSeason1DemonSlayer;
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));
    ratingsSeason1DemonSlayer.push_back(new int (5));


    dynamic_cast<Series*> (catalog.back())->setSeason("001","Kimetsu no Yaiba",idsSeason1DemonSlayer,namesSeason1DemonSlayer,lengthSeason1DemonSlayer,ratingsSeason1DemonSlayer);


    vector<string*> idsSeason2DemonSlayer;
    idsSeason2DemonSlayer.push_back(new string ("000"));
    idsSeason2DemonSlayer.push_back(new string ("001"));
    idsSeason2DemonSlayer.push_back(new string ("002"));
    idsSeason2DemonSlayer.push_back(new string ("003"));
    idsSeason2DemonSlayer.push_back(new string ("004"));
    idsSeason2DemonSlayer.push_back(new string ("005"));
    idsSeason2DemonSlayer.push_back(new string ("006"));

    vector<string*> namesSeason2DemonSlayer;
    namesSeason2DemonSlayer.push_back(new string ("Flame Hashira Kyojuro Rengoku"));
    namesSeason2DemonSlayer.push_back(new string ("Deep Sleep"));
    namesSeason2DemonSlayer.push_back(new string ("Should Have Been"));
    namesSeason2DemonSlayer.push_back(new string ("Insult"));
    namesSeason2DemonSlayer.push_back(new string ("Move Forward!"));
    namesSeason2DemonSlayer.push_back(new string ("Akaza"));
    namesSeason2DemonSlayer.push_back(new string ("Set Your Heart Ablaze"));

    vector<int*> lengthSeason2DemonSlayer;
    lengthSeason2DemonSlayer.push_back(new int (26));
    lengthSeason2DemonSlayer.push_back(new int (22));
    lengthSeason2DemonSlayer.push_back(new int (25));
    lengthSeason2DemonSlayer.push_back(new int (23));
    lengthSeason2DemonSlayer.push_back(new int (21));
    lengthSeason2DemonSlayer.push_back(new int (23));
    lengthSeason2DemonSlayer.push_back(new int (26));

    vector<int*> ratingsSeason2DemonSlayer;
    ratingsSeason2DemonSlayer.push_back(new int (5));
    ratingsSeason2DemonSlayer.push_back(new int (5));
    ratingsSeason2DemonSlayer.push_back(new int (5));
    ratingsSeason2DemonSlayer.push_back(new int (5));
    ratingsSeason2DemonSlayer.push_back(new int (5));
    ratingsSeason2DemonSlayer.push_back(new int (5));
    ratingsSeason2DemonSlayer.push_back(new int (5));

    dynamic_cast<Series*> (catalog.back())->setSeason("002","Mugen Train Arc",idsSeason2DemonSlayer,namesSeason2DemonSlayer,lengthSeason2DemonSlayer,ratingsSeason2DemonSlayer);


    vector<string*> idsSeason3DemonSlayer;
    idsSeason3DemonSlayer.push_back(new string ("000"));
    idsSeason3DemonSlayer.push_back(new string ("001"));
    idsSeason3DemonSlayer.push_back(new string ("002"));
    idsSeason3DemonSlayer.push_back(new string ("003"));
    idsSeason3DemonSlayer.push_back(new string ("004"));
    idsSeason3DemonSlayer.push_back(new string ("005"));
    idsSeason3DemonSlayer.push_back(new string ("006"));
    idsSeason1DemonSlayer.push_back(new string ("007"));
    idsSeason1DemonSlayer.push_back(new string ("008"));
    idsSeason1DemonSlayer.push_back(new string ("009"));
    idsSeason1DemonSlayer.push_back(new string ("010"));

    vector<string*> namesSeason3DemonSlayer;
    namesSeason3DemonSlayer.push_back(new string ("Sound Hashira Tengen Uzui"));
    namesSeason3DemonSlayer.push_back(new string ("Infiltrating the Entertainment District"));
    namesSeason3DemonSlayer.push_back(new string ("What Are You?"));
    namesSeason3DemonSlayer.push_back(new string ("Tonight"));
    namesSeason3DemonSlayer.push_back(new string ("Things Are Gonna Get Real Flashy!!"));
    namesSeason3DemonSlayer.push_back(new string ("Layered Memories"));
    namesSeason3DemonSlayer.push_back(new string ("Transformation"));
    namesSeason3DemonSlayer.push_back(new string ("Gathering"));
    namesSeason3DemonSlayer.push_back(new string ("Defeating an Upper Rank Demon"));
    namesSeason3DemonSlayer.push_back(new string ("Never Give Up"));
    namesSeason3DemonSlayer.push_back(new string ("No Matter How Many Lives"));

    vector<int*> lengthSeason3DemonSlayer;
    lengthSeason3DemonSlayer.push_back(new int (47));
    lengthSeason3DemonSlayer.push_back(new int (24));
    lengthSeason3DemonSlayer.push_back(new int (24));
    lengthSeason3DemonSlayer.push_back(new int (24));
    lengthSeason3DemonSlayer.push_back(new int (24));
    lengthSeason3DemonSlayer.push_back(new int (24));
    lengthSeason3DemonSlayer.push_back(new int (24));
    lengthSeason3DemonSlayer.push_back(new int (24));
    lengthSeason3DemonSlayer.push_back(new int (24));
    lengthSeason3DemonSlayer.push_back(new int (24));
    lengthSeason3DemonSlayer.push_back(new int (32));

    vector<int*> ratingsSeason3DemonSlayer;
    ratingsSeason3DemonSlayer.push_back(new int (5));
    ratingsSeason3DemonSlayer.push_back(new int (5));
    ratingsSeason3DemonSlayer.push_back(new int (5));
    ratingsSeason3DemonSlayer.push_back(new int (5));
    ratingsSeason3DemonSlayer.push_back(new int (5));
    ratingsSeason3DemonSlayer.push_back(new int (5));
    ratingsSeason3DemonSlayer.push_back(new int (5));
    ratingsSeason3DemonSlayer.push_back(new int (5));
    ratingsSeason3DemonSlayer.push_back(new int (5));
    ratingsSeason3DemonSlayer.push_back(new int (5));
    ratingsSeason3DemonSlayer.push_back(new int (5));

    dynamic_cast<Series*> (catalog.back())->setSeason("003","Entertainment District Arc",idsSeason3DemonSlayer,namesSeason3DemonSlayer,lengthSeason3DemonSlayer,ratingsSeason3DemonSlayer);

    
    catalog.push_back(new Series("006","The Witcher",2,"Tv Drama, TV Shows Based on Books, TV Action & Adventure", 4));


    vector<string*> idsSeason1TheWitcher;
    idsSeason1TheWitcher.push_back(new string ("000"));
    idsSeason1TheWitcher.push_back(new string ("001"));
    idsSeason1TheWitcher.push_back(new string ("002"));
    idsSeason1TheWitcher.push_back(new string ("003"));
    idsSeason1TheWitcher.push_back(new string ("004"));
    idsSeason1TheWitcher.push_back(new string ("005"));
    idsSeason1TheWitcher.push_back(new string ("006"));
    idsSeason1TheWitcher.push_back(new string ("007"));

    vector<string*> namesSeason1TheWitcher;
    namesSeason1TheWitcher.push_back(new string ("The End's Beginning"));
    namesSeason1TheWitcher.push_back(new string ("Four Marks"));
    namesSeason1TheWitcher.push_back(new string ("Betrayer Moon"));
    namesSeason1TheWitcher.push_back(new string ("Of Banquets, Bastards and Burials"));
    namesSeason1TheWitcher.push_back(new string ("Bottled Appetites"));
    namesSeason1TheWitcher.push_back(new string ("Rare Species"));
    namesSeason1TheWitcher.push_back(new string ("Before a Fall"));
    namesSeason1TheWitcher.push_back(new string ("Much More"));

    vector<int*> lengthSeason1TheWitcher;
    lengthSeason1TheWitcher.push_back(new int (61));
    lengthSeason1TheWitcher.push_back(new int (61));
    lengthSeason1TheWitcher.push_back(new int (67));
    lengthSeason1TheWitcher.push_back(new int (62));
    lengthSeason1TheWitcher.push_back(new int (59));
    lengthSeason1TheWitcher.push_back(new int (60));
    lengthSeason1TheWitcher.push_back(new int (48));
    lengthSeason1TheWitcher.push_back(new int (60));

    vector<int*> ratingsSeason1TheWitcher;
    ratingsSeason1TheWitcher.push_back(new int (4));
    ratingsSeason1TheWitcher.push_back(new int (3));
    ratingsSeason1TheWitcher.push_back(new int (4));
    ratingsSeason1TheWitcher.push_back(new int (4));
    ratingsSeason1TheWitcher.push_back(new int (4));
    ratingsSeason1TheWitcher.push_back(new int (4));
    ratingsSeason1TheWitcher.push_back(new int (4));
    ratingsSeason1TheWitcher.push_back(new int (4));

    dynamic_cast<Series*> (catalog.back())->setSeason("001","Season 1",idsSeason1TheWitcher,namesSeason1TheWitcher,lengthSeason1TheWitcher,ratingsSeason1TheWitcher);


    vector<string*> idsSeason2TheWitcher;
    idsSeason2TheWitcher.push_back(new string ("000"));
    idsSeason2TheWitcher.push_back(new string ("001"));
    idsSeason2TheWitcher.push_back(new string ("002"));
    idsSeason2TheWitcher.push_back(new string ("003"));
    idsSeason2TheWitcher.push_back(new string ("004"));
    idsSeason2TheWitcher.push_back(new string ("005"));
    idsSeason2TheWitcher.push_back(new string ("006"));
    idsSeason2TheWitcher.push_back(new string ("007"));

    vector<string*> namesSeason2TheWitcher;
    namesSeason2TheWitcher.push_back(new string ("A Grain of Truth"));
    namesSeason2TheWitcher.push_back(new string ("Kaer Morhen"));
    namesSeason2TheWitcher.push_back(new string ("What Is Lost"));
    namesSeason2TheWitcher.push_back(new string ("Redanian Intelligence"));
    namesSeason2TheWitcher.push_back(new string ("Turn Your Back"));
    namesSeason2TheWitcher.push_back(new string ("Dear Friend"));
    namesSeason2TheWitcher.push_back(new string ("Voleth Meir"));
    namesSeason2TheWitcher.push_back(new string ("Family"));

    vector<int*> lengthSeason2TheWitcher;
    lengthSeason2TheWitcher.push_back(new int (63));
    lengthSeason2TheWitcher.push_back(new int (58));
    lengthSeason2TheWitcher.push_back(new int (59));
    lengthSeason2TheWitcher.push_back(new int (55));
    lengthSeason2TheWitcher.push_back(new int (56));
    lengthSeason2TheWitcher.push_back(new int (57));
    lengthSeason2TheWitcher.push_back(new int (54));
    lengthSeason2TheWitcher.push_back(new int (52));

    vector<int*> ratingsSeason2TheWitcher;
    ratingsSeason2TheWitcher.push_back(new int (4));
    ratingsSeason2TheWitcher.push_back(new int (3));
    ratingsSeason2TheWitcher.push_back(new int (3));
    ratingsSeason2TheWitcher.push_back(new int (3));
    ratingsSeason2TheWitcher.push_back(new int (4));
    ratingsSeason2TheWitcher.push_back(new int (4));
    ratingsSeason2TheWitcher.push_back(new int (4));
    ratingsSeason2TheWitcher.push_back(new int (4));

    dynamic_cast<Series*> (catalog.back())->setSeason("002","Season 2",idsSeason2TheWitcher,namesSeason2TheWitcher,lengthSeason2TheWitcher,ratingsSeason2TheWitcher);


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
