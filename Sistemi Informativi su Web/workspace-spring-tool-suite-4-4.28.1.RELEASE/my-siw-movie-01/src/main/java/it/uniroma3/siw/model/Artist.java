package it.uniroma3.siw.model;

import jakarta.persistence.*;
import java.time.LocalDate;
import java.util.Objects;

@Entity
public class Artist {
	
	@Id
	@GeneratedValue( strategy = GenerationType.AUTO)
	private Long id;
	private String nome;
	private String cognome;
	private LocalDate data;
	
	
	//metodi getter e setter
	public Long getId() {
		return id;
	}
	public void setId(Long id) {
		this.id = id;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public String getCognome() {
		return cognome;
	}
	public void setCognome(String cognome) {
		this.cognome = cognome;
	}
	public LocalDate getData() {
		return data;
	}
	public void setData(LocalDate data) {
		this.data = data;
	}
	
	
	//metodi equals e hashcode
	@Override
	public int hashCode() {
		return Objects.hash(cognome, data, nome);
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Artist other = (Artist) obj;
		return Objects.equals(cognome, other.cognome) && Objects.equals(data, other.data)
				&& Objects.equals(nome, other.nome);
	}
	
	

	
	
}
