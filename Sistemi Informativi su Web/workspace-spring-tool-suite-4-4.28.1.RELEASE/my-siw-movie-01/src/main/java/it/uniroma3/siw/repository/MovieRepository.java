package it.uniroma3.siw.repository;

//import java.util.List;

import org.springframework.data.repository.CrudRepository;
import it.uniroma3.siw.model.Movie;

public interface MovieRepository extends CrudRepository<Movie, Long>{
	
	//public List<Movie> findByYear(Integer year);

	
}

//è un'interfaccia dove posso definire i metodi che verranno utilizzati
//per effettuare query al database