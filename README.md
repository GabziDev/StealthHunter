# StealthHunter

StealthHunter est un logiciel de recherche d'injections SQL, NoSQL, et XSS pour les sites web. Il permet de scanner les sites pour identifier les vulnérabilités potentielles.

## Fonctionnalités

- **Détection d'injection SQL** : Identifie les vulnérabilités d'injection SQL dans les applications web.
- **Détection d'injection NoSQL** : Recherche les failles d'injection dans les bases de données NoSQL.
- **Détection XSS** : Détecte les vulnérabilités de type Cross-Site Scripting (XSS) qui pourraient compromettre la sécurité des utilisateurs.

### Requis
- **Curl** : https://curl.se/download.html

#### Debian/Ubuntu (APT)
```bash
sudo apt update
sudo apt install curl
sudo apt install cmake 
```

#### Arch Linux (Pacman)
```bash
sudo pacman -Syu
sudo pacman -S curl
sudo pacman -S cmake
```

### Build
```bash
git clone https://github.com/GabziDev/StealthHunter.git
cd StealthHunter
mkdir build
cd build
cmake ..
make
```

(Windows)
```bash
git clone https://github.com/GabziDev/StealthHunter.git
cd StealthHunter
mkdir build
cd build
cmake -DCURL_INCLUDE_DIR="C:\path\to\curl\include" -DCURL_LIBRARY="C:\path\to\curl\build\lib\libcurl.dll.a" ..
cmake --build . --config Release
```

