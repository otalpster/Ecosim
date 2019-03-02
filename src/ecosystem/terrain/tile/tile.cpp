// File: tile.cpp

/* Custom headers */
#include "tile.hpp"
/******************/

Tile::Tile() : token(0) {}

bool Tile::set_habitat(char token) {
	if (token != '#' && token != '^' && token != '"') return false;
	if (has_habitat()) return false;
	this->token = token;
	return true;
}

char Tile::get_habitat() const {
	return token;
}

bool Tile::has_habitat() const {
	if (token == 0) return false;
	return true;
}

bool Tile::has_habitat(char token) const {
	if (this->token != token) return false;
	return true;
}
