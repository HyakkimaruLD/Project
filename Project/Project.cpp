#include <iostream>
#include <cstring>
#include "ArrayTemplate.h"

using namespace std;



int main() {
    int size = 1;
    Anime* animeArray = new Anime[size]{
        {"Naruto", "Masashi Kishimoto", "Shonen", 500}
    };
    ArrayTemp arrayManager;

    int choice = -1;
    while (choice != 0) {
        cout << "===============Anime Management System===============" << endl;
        cout << "\t1. Show all anime" << endl;
        cout << "\t2. Add anime" << endl;
        cout << "\t3. Find all information about anime by title" << endl;
        cout << "\t4. Remove anime by title" << endl;
        cout << "\t5. Edit anime (Author)" << endl;
        cout << "\t6. Sort by number of episodes" << endl;
        cout << "\t7. Sort by author" << endl;
        cout << "\t8. Sort by genre" << endl;
        cout << "\t9. Read document" << endl;
        cout << "\t10. Clear document" << endl;
        cout << "\t0. Exitt" << endl;
        cout << "=====================================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "|----------------------------------------------|" << endl;
            cout << "\tAll anime:" << endl;
            if (size == 0) {
                cout << "No anime available." << endl;
            }
            else {
                for (int i = 0; i < size; i++) {
                    cout << "\tTitle: " << animeArray[i].title << endl;
                    cout << "\tNumber of episodes: " << animeArray[i].episodes << endl;
                    cout << endl;
                }
            }
            arrayManager.update(animeArray, size);
            cout << "|----------------------------------------------|" << endl;
            break;
        case 2:
            cout << "|----------------------------------------------|" << endl;
            addNewAnime(animeArray, size);
            arrayManager.update(animeArray, size);
            cout << "|----------------------------------------------|" << endl;;
            break;




        case 3: 
            {
            cout << "|-----------------------------------|" << endl;
            char title[100];
            cout << "Enter title: ";
            cin.ignore();
            cin.getline(title, 100);
            arrayManager.findAnimeByTitle(animeArray, size, title);
            arrayManager.update(animeArray, size);
            cout << "|----------------------------------------------|" << endl;
            break;
        }
        case 4: 
        {
            cout << "|----------------------------------------------|" << endl;
            char title[100];
            cout << "Enter title: ";
            cin.ignore();
            cin.getline(title, 100);
            arrayManager.removeAnimeByTitle(animeArray, size, title);
            arrayManager.update(animeArray, size);
            cout << "|----------------------------------------------|" << endl;
            break;
        }

        case 5: 
        {
            cout << "|----------------------------------------------|" << endl;
            char title[100];
            cout << "Enter title: ";
            cin.ignore();
            cin.getline(title, 100);
            arrayManager.editAnimeAuthor(animeArray, size, title);
            arrayManager.update(animeArray, size);
            cout << "|----------------------------------------------|" << endl;;
            break;
        }

        case 6: 
        {
            cout << "|----------------------------------------------|" << endl;;
            arrayManager.sortByEpisodes(animeArray, size);
            cout << "Anime sorted by number of episodes." << endl;
            cout << "Sorted anime:" << endl;
            if (size == 0) {
                cout << "No anime available." << endl;
            }
            else {
                for (int i = 0; i < size; i++) {
                    cout << "Title: " << animeArray[i].title << endl;
                    cout << "Number of episodes: " << animeArray[i].episodes << endl;
                    cout << endl;
                }
            }
            arrayManager.update(animeArray, size);
            cout << "|----------------------------------------------|" << endl;
            break;
        }

        case 7:
        {
            cout << "|----------------------------------------------|" << endl;
            arrayManager.findAnimeByAuthor(animeArray, size);
            
            cout << "|----------------------------------------------|" << endl;
            break;
        }

        case 8:
        {
            cout << "|----------------------------------------------|" << endl;
            arrayManager.findAnimeByGenre(animeArray, size);
            arrayManager.update(animeArray, size);
            cout << "|----------------------------------------------|" << endl;
            break;
        }

        case 9:
        {
            arrayManager.readDataFromFile();
            break;
        }

        case 10:
        {
            arrayManager.clearFile();
            break;
        }
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    delete[] animeArray;
    return 0;
}



