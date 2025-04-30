# Simple Pathfinding Visualizer

## Co zawiera projekt

- Implementacja siatki jako dwuwymiarowego wektora `Node` z informacjami o położeniu, stanie (ściana, odwiedzony, część ścieżki).
- Klasy:
  - `Node` – pojedyncze pole siatki.
  - `Grid` – struktura siatki, metody rysowania i zarządzania.
  - `Pathfinder` – algorytmy wyszukiwania ścieżek (BFS).
- Funkcja śledzenia i zaznaczania przebytej ścieżki.
- Wizualizacja wyniku w terminalu (start `S`, cel `E`, ściany `#`, ścieżka `.`).

##  Jak działa

Po uruchomieniu program tworzy domyślną siatkę (np. 10x10) i ustawia:
- Punkt startowy w lewym górnym rogu `(0,0)`
- Punkt końcowy w prawym dolnym rogu `(width-1, height-1)`
- Kilka przykładowych ścian (przeszkód)

Następnie uruchamiany jest algorytm BFS, który:
- Szuka najkrótszej drogi od startu do końca.
- Zaznacza znalezioną ścieżkę na siatce.
- Wyświetla końcowy układ siatki w konsoli.

## Jak testować i zmieniać projekt

Aby przetestować działanie w różnych warunkach, można:

### Zmienić pozycje startu i końca
W pliku `main.cpp`:

```cpp
grid.setStart(0, 0);
grid.setEnd(9, 9);
