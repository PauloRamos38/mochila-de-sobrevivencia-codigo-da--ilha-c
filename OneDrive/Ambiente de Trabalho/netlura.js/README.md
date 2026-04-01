# Clone Netflix - Perfis

Projeto front-end simples inspirado na interface da Netflix, com troca de perfis e lista de filmes por usuário.

## Sobre

Este projeto foi construído com HTML, CSS e JavaScript puro para treinar estrutura de páginas, estilização e manipulação de DOM.

## Funcionalidades

- Exibição de filmes por perfil (Paulo, Tarci e Anderson)
- Seção de perfis com avatar e navegação entre páginas
- Botão Play em cada card para abrir trailer no YouTube
- Fallback de imagem quando a capa do filme falha
- Layout responsivo básico para telas menores

## Ferramentas usadas

- HTML5
- CSS3
- JavaScript (Vanilla JS)
- The Movie Database (TMDB) para capas dos filmes
- YouTube para links de trailers
- Random User API para avatares dos perfis

## Estrutura do projeto

- index.html
- paulo.html
- tarci.html
- anderson.html
- css/style.css
- js/script.js

## Como executar

1. Abra a pasta do projeto no VS Code.
2. Execute com a extensão Live Server.
3. Se o Live Server não estiver disponível, rode no terminal:

```bash
npx live-server . --port=5500
```

1. Acesse no navegador:

```text
http://localhost:5500
```

## Observação

As imagens e trailers são carregados por URLs externas.
