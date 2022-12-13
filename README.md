# Projet-INF224

---

### 4e étape : Photos et Vidéos

La méthode `play` ne doit pas avoir d'implémentation dans la classe de base. C'est donc une méthode abstraite. On le code de la façon suivante :

`virtual void play() const = 0;`

Comme une de ses méthodes est abstraite, la classe de base est désormais abstraite, ce qui signifie qu'on ne peut plus instancier des objets de cette classe.

---