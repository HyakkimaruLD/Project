#pragma once
#include <string>
#include <cstdio>
using namespace std;

struct Anime;

template<typename T>
void addItemBack(T*& arr, int& size, const T& newItem) {
    int newSize = size + 1;

    T* tempArray = new T[newSize];

    for (int i = 0; i < size; ++i) {
        tempArray[i] = arr[i];
    }
    tempArray[size] = newItem;

    delete[] arr;

    arr = tempArray;

    size = newSize;
}


struct ArrayTemp {
    void addAnime(Anime*& animeArray, int& size);
    void findAnimeByTitle(Anime* animeArray, int size, const char* title);
    void removeAnimeByTitle(Anime*& animeArray, int& size, const char* title);
    void editAnimeAuthor(Anime*& animeArray, int size, const char* title);
    void sortByEpisodes(Anime*& animeArray, int size);
    void findAnimeByGenre(Anime* animeArray, int size);
    void findAnimeByAuthor(Anime* animeArray, int size);
    void update(const Anime* animeArray, int size);
    void readDataFromFile();
    void clearFile();
};

struct Anime {
    char title[100];
    char author[100];
    char genre[100];
    int episodes;
};

void addNewAnime(Anime*& animeArray, int& size) {
    Anime newAnime;
    cout << "Enter title: ";
    cin.ignore();
    cin.getline(newAnime.title, 100);
    cout << "Enter author: ";
    cin.getline(newAnime.author, 100);
    cout << "Enter genre: ";
    cin.getline(newAnime.genre, 100);
    cout << "Enter number of episodes: ";
    cin >> newAnime.episodes;

    addItemBack(animeArray, size, newAnime);
}

void removeItemByIndex(Anime*& arr, int& size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index. Unable to remove item." << endl;
        return;
    }

    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    --size;

    Anime* tempArray = new Anime[size];

    for (int i = 0; i < size; ++i) {
        tempArray[i] = arr[i];
    }

    delete[] arr;

    arr = tempArray;
}



void ArrayTemp::removeAnimeByTitle(Anime*& animeArray, int& size, const char* title) {
    int indexToRemove = -1;
    for (int i = 0; i < size; ++i) {
        if (strcmp(animeArray[i].title, title) == 0) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove != -1) {
        removeItemByIndex(animeArray, size, indexToRemove);
        cout << "Anime \"" << title << "\" has been removed." << endl;
    }
    else {
        cout << "Anime \"" << title << "\" not found." << endl;
    }
}



void ArrayTemp::findAnimeByTitle(Anime* animeArray, int size, const char* title) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (strcmp(animeArray[i].title, title) == 0) {
            found = true;
            cout << "\tTitle: " << animeArray[i].title << endl;
            cout << "\tAuthor: " << animeArray[i].author << endl;
            cout << "\tGenre: " << animeArray[i].genre << endl;
            cout << "\tEpisodes: " << animeArray[i].episodes << endl;
            break;
        }
    }
    if (!found) {
        cout << "Anime \"" << title << "\" not found." << endl;
    }
}


void ArrayTemp::editAnimeAuthor(Anime*& animeArray, int size, const char* title) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(animeArray[i].title, title) == 0) {
            cout << "Enter new author for anime \"" << title << "\": ";
            cin.getline(animeArray[i].author, 100);
            cout << "Author for anime \"" << title << "\" has been updated." << endl;
            return;
        }
    }
    cout << "Anime \"" << title << "\" not found." << endl;
}



void ArrayTemp::sortByEpisodes(Anime*& animeArray, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (animeArray[j].episodes > animeArray[j + 1].episodes) {
                Anime temp = animeArray[j];
                animeArray[j] = animeArray[j + 1];
                animeArray[j + 1] = temp;
            }
        }
    }
}



void ArrayTemp::findAnimeByGenre(Anime* animeArray, int size) {
    char genreToFind[100];
    cout << "Enter genre to find: ";
    cin.ignore();
    cin.getline(genreToFind, 100);

    cout << "\tAnime with genre \"" << genreToFind << "\":" << endl;
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (strcmp(animeArray[i].genre, genreToFind) == 0) {
            found = true;
            cout << "\tTitle: " << animeArray[i].title << endl;
            cout << "\tGenre: " << animeArray[i].genre << endl;
            cout << endl;
        }
    }

    if (!found) {
        cout << "No anime found with genre \"" << genreToFind << "\"" << endl;
    }
}




void ArrayTemp::findAnimeByAuthor(Anime* animeArray, int size) {
    char authorToFind[100];
    cout << "Enter author to find: ";
    cin.ignore();
    cin.getline(authorToFind, 100);

    cout << "\tAnime by author \"" << authorToFind << "\":" << endl;
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (strcmp(animeArray[i].author, authorToFind) == 0) {
            found = true;
            cout << "\tAuthor: " << animeArray[i].author << endl;
            cout << "\tTitle: " << animeArray[i].title << endl;
            cout << endl;
        }
    }
    update(animeArray, size);
    if (!found) {
        cout << "No anime found by author \"" << authorToFind << "\"" << endl;
    }
}



void ArrayTemp::update(const Anime* animeArray, int size) {
    FILE* outFile;
    errno_t err = fopen_s(&outFile, "anime_database.txt", "w");
    if (err != 0) {
        cout << "Error: Unable to open file for writing." << endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        fprintf(outFile, "\tTitle: %s\n", animeArray[i].title);
        fprintf(outFile, "\tAuthor: %s\n", animeArray[i].author);
        fprintf(outFile, "\tGenre: %s\n", animeArray[i].genre);
        fprintf(outFile, "\tEpisodes: %d\n", animeArray[i].episodes);
        fprintf(outFile, "\n");
    }

    fclose(outFile);
    cout << "Data has been successfully saved to 'anime_database.txt'." << endl;
}



void ArrayTemp::readDataFromFile() {
    FILE* inFile;
    fopen_s(&inFile, "anime_database.txt", "r");
    if (!inFile) {
        cout << "Error: Unable to open file for reading." << endl;
        return;
    }

    cout << "Data read from 'anime_database.txt':" << endl;
    char buffer[1000];
    while (fgets(buffer, 1000, inFile) != NULL) {
        cout << buffer;
    }

    fclose(inFile);
}


void ArrayTemp::clearFile() {
    FILE* file;
    errno_t err = fopen_s(&file, "anime_database.txt", "w");
    if (err != 0) {
        cout << "Error: Unable to open file for clearing." << endl;
        return;
    }

    fclose(file);
    cout << "File 'anime_database.txt' has been cleared." << endl;
}