#!/bin/bash

# Путь к проектам
projects_path="/home/denis/NG_Curses/NG_2024_Denis_Parashchenko/Lesson_1"

# Список проектов
projects=("Task_1" "Task_2" "Task_3" "Task_4" "Task_5" "Task_6")

# Функция для отображения меню
show_menu() {
    echo "Выберите проект для запуска:"
    for i in "${!projects[@]}"; do
        echo "$((i + 1)). ${projects[$i]}"
    done
    echo "0. Выйти"
}

# Функция для запуска проекта в gnome-terminal
run_project() {
    local project_name=$1
    gnome-terminal -- bash -c "$projects_path/$project_name/build/Desktop_Qt_6_7_2-Debug/$project_name; exec bash"
}

while true; do
    show_menu
    read -p "Введите номер проекта: " choice

    if [[ $choice -eq 0 ]]; then
        echo "Выход..."
        exit 0
    elif [[ $choice -gt 0 && $choice -le ${#projects[@]} ]]; then
        run_project "${projects[$((choice - 1))]}"
    else
        echo "Неверный выбор, попробуйте снова."
    fi
done

