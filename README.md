Descrierea temei 2 - LAN PARTY 2024

Tema mea este concepută pentru a gestiona un turneu tip LanParty cu 32 de echipe, cu generare și procesare de meciuri, determinare câștigător și afișare prestigiu pentru fiecare echipă.

Structura proiectului

Fișierul pentru date de intrare conține datele de intrare despre echipe: numele și scorurile acestora.

Fișierele pentru date de ieșire trebuie să fie formatate după regulile din checker și să conțină matricea de adiacență a grafului sau prestigiul fiecărei echipe, urmate de numele acesteia. 

Checker-ul rulează comanda ./clasament fisierIn fisierOut1 fisierOut2 pentru verificarea corectitudinii algoritmilor.

Proiectul este constituit din mai multe fișiere cu diferite funcționalități:
- turneu-main.c -> conține main-ul(cu manipularea fișierelor) prin care se citesc datele de intrare(nume și scorul echipei) pentru generarea meciurilor turneului într-o manieră specifică, conform cerințelor; apoi creează matricea de adiacență și o afișează în fișier; apoi calculează prestigiului fiecărei echipe în funcție de performanța lor în turneu și salvează rezultatele într-un fișier de ieșire.
  
- functii.c și functii.h -> fișierul sursă și biblioteca aferentă cu structuri specifice cozilor, grafurilor și definițiile și prototipurile funcțiilor utilizate în program.

Licență
Acest program este distribuit sub Licența MIT.
