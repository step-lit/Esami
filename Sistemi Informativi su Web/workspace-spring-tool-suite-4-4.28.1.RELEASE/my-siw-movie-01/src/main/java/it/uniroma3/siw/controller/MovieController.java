package it.uniroma3.siw.controller;

import org.springframework.beans.factory.annotation.Autowired; 
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;

import it.uniroma3.siw.model.Movie;
import it.uniroma3.siw.service.MovieService;

@Controller
public class MovieController {
	
	@Autowired
	MovieService movieService;
	
	@GetMapping("/formNewMovie")
	public String formNewMovie(Model model) {
		model.addAttribute("movie", new Movie());
		return "formNewMovie.html";
	}
	
	@PostMapping("/movie")
	public String newMovie(@ModelAttribute("movie") Movie movie, Model model) {
		this.movieService.save(movie);
	    //model.addAttribute("movie", movie);
	    return "redirect:movie/"+movie.getId();
	}
	
	@GetMapping("/movie/{id}")
	public String getMovie(@PathVariable("id") Long id, Model model) {
		model.addAttribute("movie", this.movieService.getMovieById(id));
		return "movie.html";
	}

	@GetMapping("/movie")
	public String showMovies(Model model) {
		model.addAttribute("movies", this.movieService.getAllMovies());
		return "movies.html";
	}
}
