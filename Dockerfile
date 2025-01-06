# Utiliser une image de base officielle de Debian
FROM debian:latest

# Mettre à jour les paquets et installer les dépendances nécessaires
RUN apt-get update && apt-get install -y iproute2 \
    gcc \
    make \
    xorg \
    libx11-dev \
    libxext-dev \
    libbsd-dev \
    valgrind \
    iproute2 \
    && rm -rf /var/lib/apt/lists/*

# Définir le répertoire de travail
WORKDIR /app

# Copier le code source dans le conteneur
COPY . .

# Définir la commande par défaut pour ouvrir un shell
CMD ["/bin/bash"]