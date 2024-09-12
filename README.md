# StealthHunter | Chasseur Furtif

StealthHunter est un logiciel de test de sécurité conçu pour détecter les vulnérabilités dans les sites web, y compris les injections SQL, NoSQL, et XSS. Il offre également d'autres fonctionnalités !

## Fonctionnalités
- **Dir Busting** : Effectue une recherche exhaustive des répertoires et fichiers cachés sur un serveur web en testant diverses listes de chemins et de noms de fichiers. Cette fonctionnalité aide à découvrir des ressources non indexées qui pourraient présenter des vulnérabilités.
- **Détection d'injection SQL** : Identifie les vulnérabilités d'injection SQL dans les applications web.
- **Détection d'injection NoSQL** : Recherche les failles d'injection dans les bases de données NoSQL.
- **Détection XSS** : Détecte les vulnérabilités de type Cross-Site Scripting (XSS) qui pourraient compromettre la sécurité des utilisateurs.

### Requis
- **Curl** : https://curl.se/download.html

#### Debian/Ubuntu (APT)
```bash
sudo apt update
sudo apt install build-essential cmake curl git libcurl4-openssl-dev
```

#### Arch Linux (Pacman)
```bash
sudo pacman -Syu
sudo pacman -S base-devel cmake curl git libcurl-compat
```

### Build
```bash
git clone https://github.com/GabziDev/StealthHunter.git
cd StealthHunter
mkdir build
cd build
cmake ..
make
make install
```

## Execution
```bash
StealthHunter
```

