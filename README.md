# Projet-INF224

---

## 4e étape : Photos et Vidéos

La méthode `play` ne doit pas avoir d'implémentation dans la classe de base. C'est donc une méthode abstraite. On le code de la façon suivante :

`virtual void play() const = 0;`

Comme une de ses méthodes est abstraite, la classe de base est désormais abstraite, ce qui signifie qu'on ne peut plus instancier des objets de cette classe.

---

## 5e étape : Traitement uniforme

On peut traiter des objets photos et vidéos avec le même code grâce au polymorphisme : les classes `Video` et `Photo` héritent de la superclasse `AbstractMedia`.

Toutefois, on ne code pas exactement de la même façon qu'en Java : on doit utiliser le déréférencement pour accéder aux méthodes des objets vidéos ou photos. Par exemple :

`objects[i]->play();`

En Java, on écrirait plutôt :

`objects[i].play();`

Cette différence est due au fait que le tableau `objects` contient ici des pointeurs vers les objets. Il est également possible de créer des tableaux d'objets en C++ : dans ce cas, on n'aurait pas besoin de déréférencer. En Java, on a une seule possibilité pour les tableaux d'objets : on fait des tableaux de références. Il n'y a donc pas besoin de distinguer deux cas, et le déréférencement est fait automatiquement.

Ici, il est nécessaire d'utiliser un tableau de pointeurs parce que les éléments du tableau n'ont pas le même type, et donc ne prennent pas la même taille en mémoire. Or, les éléments du tableau seront attribués la même place en mémoire.

---

