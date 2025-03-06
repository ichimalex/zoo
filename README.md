# Birds Management System

## Overview
This C++ program models a bird management system using object-oriented programming principles. The system categorizes birds into flying (`Zburatoare`) and non-flying (`Nezburatoare`) types, allows adding birds to a collection, and provides various functionalities to manipulate and analyze the data.

## Features
- **Add Birds**: Users can add both flying and non-flying birds with specific attributes.
- **Display Birds**: Prints details of all stored birds.
- **Filter Birds**: Finds birds based on type and size.
- **Calculate Surface Area**: Computes a characteristic value for each bird.
- **Sort Birds**: Sorts the collection based on calculated surface area.
- **Compare Totals**: Compares total surface area between flying and non-flying birds.

## Classes
### `Pasare` (Base Class)
- **Attributes**: `tip` (type), `nume` (name), `dim` (size)
- **Virtual methods**: `afisare()`, `sup()` (computes surface area)

### `Zburatoare` (Flying Birds)
- **Inherits from**: `Pasare`
- **Additional attribute**: `batai` (wing beats per second)
- **Overrides**: `afisare()`, `sup()`

### `Nezburatoare` (Non-Flying Birds)
- **Inherits from**: `Pasare`
- **Additional attribute**: `culoare` (color)
- **Overrides**: `afisare()`, `sup()`

### `Gestionare`
- **Stores** a collection of `Pasare` objects in a vector
- **Provides methods to**: add, display, sort, and analyze birds
