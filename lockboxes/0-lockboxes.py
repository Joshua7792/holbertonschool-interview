#!/usr/bin/python3
"""
Module to determine if all lockboxes can be opened
"""


def canUnlockAll(boxes):
    """
    Determine if all boxes can be unlocked.
    Args:
        boxes (list): (
            A list of lists where each list contains keys to other boxes.
        )
    Returns:
        bool: True if all boxes can be opened, False otherwise.
    """
    if not boxes:
        return False

    # Crear un conjunto para las cajas abiertas
    opened = set([0])  # La primera caja siempre está abierta
    keys = set(boxes[0])  # Llaves de la primera caja

    while keys:
        key = keys.pop()  # Tomar una llave
        if key < len(boxes) and key not in opened:
            opened.add(key)  # Abrir la caja
            keys.update(boxes[key])  # Añadir nuevas llaves encontradas

    # Todas las cajas deben estar abiertas
    return len(opened) == len(boxes)
