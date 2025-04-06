package it.uniroma3.siw.model;

import java.time.LocalDateTime;
import java.util.List;
import java.util.Objects;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.ManyToOne;
import jakarta.persistence.OneToMany;
import jakarta.persistence.Table;

@Entity
@Table(name="orders")
public class Order {

	@Id
	@GeneratedValue(strategy=GenerationType.AUTO)
	private Long id;
	
	private LocalDateTime creationTime;
	
	@OneToMany
	@JoinColumn(name="orders_id")  //questa è un'associazione OneToMany unidirezionale
	private List<OrderLine> orderLines; //JPA crea in automatico una tabella ulteriore con il join dei valori
										//per forzare la foreign key nella tabella many andiamo ad aggiungere JoinColumn(name="chiave da
										//inserire nell'altra tabella many") nella tabella one
	
										//in OrderLine non mettiamo niente perché è unidirezionale
	
	@ManyToOne
	private Customer customer;
	

	public Customer getCustomer() {
		return customer;
	}

	public void setCustomer(Customer customer) {
		this.customer = customer;
	}

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public LocalDateTime getCreationTime() {
		return creationTime;
	}

	public void setCreationTime(LocalDateTime creationTime) {
		this.creationTime = creationTime;
	}

	public List<OrderLine> getOrderLines() {
		return orderLines;
	}

	public void setOrderLines(List<OrderLine> orderLines) {
		this.orderLines = orderLines;
	}

	@Override
	public int hashCode() {
		return Objects.hash(creationTime, customer, orderLines);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Order other = (Order) obj;
		return Objects.equals(creationTime, other.creationTime) && Objects.equals(customer, other.customer)
				&& Objects.equals(orderLines, other.orderLines);
	}

	
	
	
	
	
	
	
}
