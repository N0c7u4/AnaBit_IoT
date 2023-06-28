# Autor



<div class="profile-picture" style="width: 150px; height: 150px; overflow: hidden; border-radius: 50%;">
    <img style="width: 100%; height: auto; border-radius: 50%;" alt="" src="https://avatars.githubusercontent.com/u/108634840?v=4" class="avatar avatar-user width-full border color-bg-default" width="260" height="260">
  </div>


<h2><span style="font-family: 'Roboto', sans-serif; font-size: 34px;"><strong>Ing Steven Florez</strong></span></h2>
> Repositorio:  <a href="https://github.com/St3v3n-4n4" target="_blank" class="hljs-tag">St3v3n-4n4</a>

<div id="profile-bio"></div>

  <script>
    document.addEventListener("DOMContentLoaded", function() {
      var xhr = new XMLHttpRequest();
      xhr.open("GET", "https://api.github.com/users/St3v3n-4n4"); // Reemplaza "TU_USUARIO_GITHUB" con tu nombre de usuario de GitHub
      xhr.onreadystatechange = function() {
        if (xhr.readyState === 4 && xhr.status === 200) {
          var response = JSON.parse(xhr.responseText);
          var profileBioElement = document.getElementById("profile-bio");
          profileBioElement.textContent = response.bio; // Muestra el texto en la página web
        }
      };
      xhr.send();
    });
  </script>
