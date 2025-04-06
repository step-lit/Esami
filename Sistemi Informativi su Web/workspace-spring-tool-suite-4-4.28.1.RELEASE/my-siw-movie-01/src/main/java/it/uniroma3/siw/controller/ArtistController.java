package it.uniroma3.siw.controller;


import it.uniroma3.siw.service.ArtistService;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;


@Controller
public class ArtistController {

	@Autowired
	ArtistService artistService;
	
	@GetMapping("/artist/{id}")
	public String getArtist(@PathVariable("id") Long id, Model model) {
		model.addAttribute("artist", this.artistService.getArtistById(id));
		return "artist.html";
	}
	
	@GetMapping("/artist")
	public String getArtist(Model model) {
		model.addAttribute("artist", this.artistService.getAllArtists());
		return "artists.html"; //è una vista html diversa dalla precedente
	}
	
}
