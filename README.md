# 🎮 So Long (Mad Ting)

Un juego de laberinto 2D desarrollado como proyecto para 42 School, implementado en C con MiniLibX.

## 📋 Descripción

**So Long** es un juego tipo laberinto donde el jugador debe:
- ✅ Recolectar todos los items (C) en el mapa
- 🏁 Llegar a la salida (E) después de recolectar todos los items
- ⚔️ Evitar enemigos (K) que se mueven automáticamente
- 🏰 Navegar por un laberinto con paredes (1) y caminos (0)

## 🎯 Características

- **Gráficos pixel art** con sprites animados
- **Sistema de animaciones** para jugador, enemigos y salida
- **Validación completa de mapas** con pathfinding
- **Contador de movimientos** en tiempo real
- **Múltiples controles** (WASD + flechas)
- **Gestión de errores** robusta
- **Sprites personalizados** con temática medieval

## 🚀 Instalación y Uso

### Prerrequisitos
```bash
# Asegúrate de tener X11 y las librerías de desarrollo
sudo apt-get install libxext-dev libxrandr-dev libx11-dev libbsd-dev libssl-dev
```

### Compilación
```bash
# Compilar el proyecto
make

# Ejecutar con un mapa
./so_long maps/map0.ber

# Limpieza
make clean
make fclean
```

### Controles
- **W / ↑** - Mover arriba
- **A / ←** - Mover izquierda
- **S / ↓** - Mover abajo
- **D / →** - Mover derecha
- **ESC** - Salir del juego

## 📁 Estructura del Proyecto

```
so_long/
├── src/                 # Código fuente
│   ├── main.c          # Punto de entrada
│   ├── hooks.c         # Manejo de input
│   ├── load_img.c      # Carga de sprites
│   ├── map_check.c     # Validación de mapas
│   └── ...
├── headers/            # Archivos de cabecera
│   ├── so_long.h       # Prototipos de funciones
│   ├── structs.h       # Definición de estructuras
│   └── define.h        # Constantes y macros
├── libft/              # Librería personal (42)
├── sprites/            # Assets gráficos
│   ├── player/         # Sprites del jugador
│   ├── wall/           # Sprites de paredes
│   ├── exit/           # Sprites de salida
│   └── ...
├── maps/               # Mapas de ejemplo
└── minilibx-linux/     # MiniLibX modificado
```

## 🎨 Assets

Los sprites están organizados temáticamente:
- **Jugador**: Animaciones de movimiento y idle
- **Paredes**: 4 variaciones para diversidad visual
- **Enemigos**: Skull sprites animados
- **Coleccionables**: Skull dorado
- **Salida**: Animación de portal mágico
- **Suelo**: Textura de piedra

## 🔧 Características Técnicas

- **Librería gráfica**: MiniLibX con soporte de transparencia
- **Gestión de memoria**: Sin leaks (verificado con Valgrind)
- **Validación**: Pathfinding con flood fill
- **Animaciones**: Frame-based animation system
- **Input handling**: Event-driven architecture

## 📝 Formato de Mapas

Los mapas deben usar los siguientes caracteres:
- `1` - Paredes (deben rodear completamente el mapa)
- `0` - Caminos transitables
- `P` - Posición inicial del jugador (solo una)
- `C` - Coleccionables (al menos uno)
- `E` - Salida (solo una)
- `K` - Enemigos (opcionales)

**Ejemplo de mapa válido:**
```
1111111111
111C111101
11000E0001
1111P11111
1K00000C11
1111111111
```

## 🐛 Troubleshooting

### Problemas con sprites transparentes
Si ves fondos negros bajo los sprites:
1. Reemplaza `minilibx-linux/mlx_xpm.c` con `minilibx-linux/mlx_xpm.c.ok`
2. Recompila: `cd minilibx-linux && make clean && make`
3. Recompila el proyecto: `make re`

### Mapas no válidos
El juego valida automáticamente:
- Mapa rodeado de paredes
- Al menos 1 coleccionable
- Exactamente 1 jugador y 1 salida
- Camino válido hacia todos los elementos

## 📊 Información del Proyecto

- **Lenguaje**: C
- **Framework**: MiniLibX
- **Norma**: Norminette (42 School)
- **Estado**: ✅ Completado y Optimizado
- **Plataforma**: Linux (X11)
- **Calidad de Código**: ✅ Revisado y mejorado

## 🎓 Sobre 42 School

Este proyecto forma parte del currículo de 42 School, donde se enfoca en:
- Programación de bajo nivel en C
- Gestión manual de memoria
- Gráficos por computadora
- Algoritmos de pathfinding
- Desarrollo de videojuegos básicos

---

Nota sobre MiniLibX y transparencia XPM

- Para que los sprites XPM con `c None` respeten transparencia y no tapen el suelo, este proyecto usa la variante de MiniLibX que aplica clip mask.
- Archivo en uso: `minilibx-linux/mlx_xpm.c` (contenido equivalente a `mlx_xpm.c.ok`).
- Si clonas desde cero y ves fondos negros bajo los objetos:
  1) Sustituye `minilibx-linux/mlx_xpm.c` por el contenido de `minilibx-linux/mlx_xpm.c.ok`.
  2) Compila MiniLibX y el proyecto:
     - `cd minilibx-linux && make clean && make`
     - `cd .. && make re`
  3) Asegúrate de enlazar con `-lXpm -lz` (ya incluido en el `Makefile`).

Esto asegura que MLX genere la máscara de recorte y dibuje correctamente los sprites encima del suelo.

**¡Disfruta del juego! 🎮**


