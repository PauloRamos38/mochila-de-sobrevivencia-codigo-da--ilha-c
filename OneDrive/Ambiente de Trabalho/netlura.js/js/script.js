const container = document.querySelector(".movies");
const inicioLink = document.querySelector("#inicio-link");
const profilesSection = document.querySelector("#profiles");
const profilesList = document.querySelector(".profiles-list");
const moviesTitle = document.querySelector(".row h3");
const fallbackCover = "https://dummyimage.com/600x860/151515/ffffff&text=Sem+Capa";
const currentProfile = document.body.dataset.profile || "Paulo";

const profiles = [
  {
    name: "Paulo",
    avatar: "https://randomuser.me/api/portraits/men/32.jpg",
    page: "paulo.html"
  },
  {
    name: "Tarci",
    avatar: "https://randomuser.me/api/portraits/women/44.jpg",
    page: "tarci.html"
  },
  {
    name: "Anderson",
    avatar: "https://randomuser.me/api/portraits/men/67.jpg",
    page: "anderson.html"
  }
];

const moviesByProfile = {
  Paulo: [
    {
      title: "O Protetor: Capitulo Final (Denzel W.)",
      cover: "https://image.tmdb.org/t/p/w780/b0Ej6fnXAP8fK75hlyi2jKqdhHz.jpg",
      trailer: "https://www.youtube.com/watch?v=19ikl8vy4zs"
    },
    {
      title: "John Wick",
      cover: "https://image.tmdb.org/t/p/w780/fZPSd91yGE9fCcCe6OoQr6E3Bev.jpg",
      trailer: "https://www.youtube.com/watch?v=2AUmvWm5ZDQ"
    },
    {
      title: "O Ultimato Bourne",
      cover: "https://media.themoviedb.org/t/p/w600_and_h900_face/27XjtVdi6zbNni68wtmGdlCODCR.jpg",
      trailer: "https://www.youtube.com/watch?v=ZT2ZxjUjSo0"
    }
  ],
  Tarci: [
    {
      title: "Avatar",
      cover: "https://image.tmdb.org/t/p/w780/kyeqWdyUXW608qlYkRqosgbbJyK.jpg",
      trailer: "https://www.youtube.com/watch?v=5PSNL1qE6VY"
    },
    {
      title: "Matrix",
      cover: "https://image.tmdb.org/t/p/w780/f89U3ADr1oiB1s9GkdPOEpXUk5H.jpg",
      trailer: "https://www.youtube.com/watch?v=vKQi3bBA1y8"
    },
    {
      title: "Batman",
      cover: "https://image.tmdb.org/t/p/w780/74xTEgt7R36Fpooo50r9T25onhq.jpg",
      trailer: "https://www.youtube.com/watch?v=mqqft2x_Aa4"
    }
  ],
  Anderson: [
    {
      title: "Batman",
      cover: "https://image.tmdb.org/t/p/w780/74xTEgt7R36Fpooo50r9T25onhq.jpg",
      trailer: "https://www.youtube.com/watch?v=mqqft2x_Aa4"
    },
    {
      title: "Matrix",
      cover: "https://image.tmdb.org/t/p/w780/f89U3ADr1oiB1s9GkdPOEpXUk5H.jpg",
      trailer: "https://www.youtube.com/watch?v=vKQi3bBA1y8"
    },
    {
      title: "Avatar",
      cover: "https://image.tmdb.org/t/p/w780/kyeqWdyUXW608qlYkRqosgbbJyK.jpg",
      trailer: "https://www.youtube.com/watch?v=5PSNL1qE6VY"
    },
    {
      title: "Heroi (Jet Li)",
      cover: "https://media.themoviedb.org/t/p/w600_and_h900_face/bCxoK5adJ4bf8lQBTYoyiGQSw9u.jpg",
      trailer: "https://www.youtube.com/watch?v=_USDk5jaGek"
    }
  ]
};

function renderMovies(profileName) {
  if (!container) {
    return;
  }

  const movies = moviesByProfile[profileName] || [];
  container.innerHTML = "";

  if (moviesTitle) {
    moviesTitle.textContent = `Filmes de ${profileName}`;
  }

  movies.forEach((movie, index) => {
    const card = document.createElement("article");
    card.classList.add("movie");
    card.style.animationDelay = `${index * 0.1}s`;

    card.innerHTML = `
      <img class="movie-cover" src="${movie.cover}" alt="Capa do filme ${movie.title}">
      <div class="movie-info">
        <p class="movie-title">${movie.title}</p>
        <button class="play-btn" type="button" data-trailer="${movie.trailer}">Play</button>
      </div>
    `;

    const playButton = card.querySelector(".play-btn");
    const coverImage = card.querySelector(".movie-cover");

    coverImage?.addEventListener("error", () => {
      coverImage.src = fallbackCover;
    });

    playButton?.addEventListener("click", () => {
      const trailerUrl = playButton.getAttribute("data-trailer");
      if (trailerUrl) {
        window.open(trailerUrl, "_blank", "noopener,noreferrer");
      }
    });

    container.appendChild(card);
  });
}

function renderProfiles(activeProfileName) {
  if (!profilesList || !profilesSection) {
    return;
  }

  profilesList.innerHTML = "";

  profiles.forEach((profile) => {
    const profileItem = document.createElement("article");
    profileItem.classList.add("profile-item");
    if (profile.name === activeProfileName) {
      profileItem.classList.add("active");
    }

    profileItem.innerHTML = `
      <img class="profile-avatar" src="${profile.avatar}" alt="Foto do perfil ${profile.name}">
      <p class="profile-name">${profile.name}</p>
    `;

    profileItem.addEventListener("click", () => {
      window.location.href = profile.page;
    });

    profilesList.appendChild(profileItem);
  });

  profilesSection.hidden = false;
}

inicioLink?.addEventListener("click", (event) => {
  event.preventDefault();
  renderProfiles(currentProfile);
  renderMovies(currentProfile);
  profilesSection.scrollIntoView({ behavior: "smooth", block: "start" });
});

renderProfiles(currentProfile);
renderMovies(currentProfile);