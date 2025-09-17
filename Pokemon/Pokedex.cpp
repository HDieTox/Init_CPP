//
// Created by tom on 9/8/25.
//

#include "headers/Pokedex.h"

std::vector<Pokemon> lireCSV(const std::string& nomFichier) {
    std::vector<Pokemon> pokemons;
    std::ifstream fichier(nomFichier); // Ouvre le fichier
    if (!fichier.is_open()) { // Vérifie si le fichier est bien ouvert
        std::cerr << "Impossible d'ouvrir le fichier : " << nomFichier << std::endl;
    }
    std::string ligne;
    std::getline(fichier, ligne);
    while (std::getline(fichier, ligne)) { // Lit le fichier ligne par ligne
        std::stringstream ss(ligne); // Utilise un flux pour diviser la ligne
        std::string cellule;
        std::vector<std::string> donneesLigne;
        // Divise la ligne en cellules séparées par des virgules
        while (std::getline(ss, cellule, ',')) {
            donneesLigne.push_back(cellule); // Ajoute chaque cellule au vecteur
        }

        pokemons.push_back(Pokemon(
            stoi(donneesLigne.at(0)),
            donneesLigne.at(1),
            stoi(donneesLigne.at(4)),
            stoi(donneesLigne.at(5)),
            stoi(donneesLigne.at(6)),
            stoi(donneesLigne.at(10))));
    }
    fichier.close(); // Ferme le fichier
    return pokemons;
}

Pokedex* Pokedex::pinstance = nullptr;

Pokedex::Pokedex(const std::string &path_to_pokedex) : SetOfPokemon() {
    this->path_to_pokedex = path_to_pokedex;
    listPokemon=lireCSV(path_to_pokedex);
    std::cout<< "Succesfully read "<< listPokemon.size() << std::endl;
}

Pokedex* Pokedex::getInstance() {
    if (pinstance == nullptr) {
        pinstance = new Pokedex("../ressource/pokedex.csv");
    }
    return pinstance;
}

Pokemon Pokedex::copyPokemonbyName(std::string &pokemonName) {
    Pokemon copied(this->findByName(pokemonName));
        return copied;
}

int Pokedex::getPokedexSize() {
    return listPokemon.size();
}
