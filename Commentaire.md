
### Dans Pokemon.cpp: 
#### :)
 *  Les points de vies sont saturés à 0 


#### :(
* utiliser strike() quand un pokémon est mort est la même chose que avoir tué un pokémon d'un seul coup



### Dans SetOfPokemon.cpp:
#### :(
*  l'argument  name dans```SetOfPokemon::findByName( std::string& name) const{...}```
est copié à chaque fois il vaut mieux en faire un const reference (**corrigé**)


### Général:
* c'est toujours bien d'avoir des ```[[nodiscard]]``` pour que l'IDE sache que tu dois récupérer quelque chose en faisant cette commande.

* Le mauvais champ est lu pour la génération du pokémon et pas le temps de corriger
