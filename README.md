# Philosophers

A C implementation of the dining philosophers simulation using POSIX threads and mutexes. Philosophers share forks and alternate between eating, sleeping, and thinking.

## Build

Requires Make, a C compiler, and POSIX threads.

```sh
make -C philo
```

The executable is `philo/philo`.

## Run

```sh
./philo/philo number_of_philosophers time_to_die time_to_eat time_to_sleep [meals_per_philosopher]
./philo/philo 5 800 200 200 7
```

Times are in milliseconds. The parser accepts 1–400 philosophers, positive timing values, and a nonnegative optional meal count. A meal count of zero exits immediately. Omitting it runs without a meal limit, until the simulation otherwise stops.

## Layout

- `philo/parsing.c`: argument validation.
- `philo/init.c` and `philo/thread.c`: initialization and thread coordination.
- `philo/routine.c`: eating, sleeping, and thinking.
- `philo/time.c`: timing helpers.
- `philo/clean.c`: cleanup.

## Clean

```sh
make -C philo clean   # Remove object files
make -C philo fclean  # Also remove the executable
```
