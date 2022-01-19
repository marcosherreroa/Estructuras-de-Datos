//Marcos Herrero

#ifndef ipud_h
#define ipud_h

#include <string>
#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>

using cancion = std::string;
using artista = std::string;
using duracion = int;

struct infoCancion {
	std::string artista;
	int duracion;
	std::list<cancion>::iterator itPlaylist;
	std::list<cancion>::iterator itReproducidas;
};

class ipud {
private:
	std::unordered_map<cancion, infoCancion> canciones;
	std::list<cancion> playlist;
	duracion durPlaylist;
	std::list<cancion> reproducidas;

public:
	ipud() :durPlaylist(0) {};

	void addSong(cancion const & S, artista const & A, duracion const & D) { //coste constante
		auto it = canciones.find(S);
		if (it != canciones.end()) throw std::domain_error("addSong");

		infoCancion info;
		info.artista = A;
		info.duracion = D;
		info.itPlaylist = playlist.end();
		info.itReproducidas = reproducidas.end();
		canciones.insert(it, { S, info });
	}

	void addToPlaylist(cancion const & S) { // coste constante
		auto it = canciones.find(S);
		if (it == canciones.end()) throw std::domain_error("addToPlaylist");
		if (it->second.itPlaylist == playlist.end()) {
			playlist.push_back(S);
			it->second.itPlaylist= --playlist.end();
			durPlaylist += it->second.duracion;
		}
	}

	cancion const & current()const { // coste constante
		if (playlist.size() == 0)throw std::domain_error("current");
		return playlist.front();
	}

	void play() { // coste constante
		if (playlist.size() != 0) {
			auto it = canciones.find(playlist.front());
			if (it->second.itReproducidas != reproducidas.end()) {
				reproducidas.erase(it->second.itReproducidas);
				it->second.itReproducidas = reproducidas.end();
			}
		    
			reproducidas.push_front(playlist.front());
			it->second.itReproducidas = reproducidas.begin();
			it->second.itPlaylist = playlist.end();
			durPlaylist -= it->second.duracion;
			playlist.pop_front();
		}
	}

	duracion const & totalTime()const { // coste constante
		return durPlaylist;
	}

	std::list<cancion> recent(int N) {//coste lineal respecto a N
		std::list<cancion> lista;

		auto it = reproducidas.begin();
		int i = 0;
		while (i < N && it != reproducidas.end()) {
			lista.push_back(*it);
			++it;
			++i;
		}

		return lista;
	}

	void deleteSong(cancion const & S) { //coste constante
		auto it = canciones.find(S);
		if (it != canciones.end()) {
			if (it->second.itPlaylist != playlist.end()) {
				durPlaylist -= it->second.duracion;
				playlist.erase(it->second.itPlaylist);
			}
			if (it->second.itReproducidas != reproducidas.end()) reproducidas.erase(it->second.itReproducidas);
			canciones.erase(it);
			}
		}
};

#endif