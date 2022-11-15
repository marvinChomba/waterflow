import React, { Component } from 'react';
import logo from './logo.svg';
import './App.css';
// import axios from "axios";


class App extends Component {

  state = {
    places: [],
    selected: {},
    loading: false
  }

  componentDidMount() {
    fetch('https://aqueous-cliffs-21718.herokuapp.com/')
    .then((response) => response.json())
    .then(data => {
        this.setState({places:data})
    });



}
  render() {
    const submit = e => {
      console.log("Submitted");
      console.log(this.state.places)
    }

    const handleFormChange = (e) => {
      console.log(e.target.value)

      let selected = this.state.places.filter(place => {
        return place.addy == e.target.value
      })

      // console.log(selected)
      this.setState({selected: selected})
      console.log(this.state.selected)
    }
    const showStuff = () => {
      if(this.state.places.length > 0) {
        return (        <div class="content">
        <h1>WATERFLOW MONITOR</h1>
        <form class="form-field">
          <div>
          <select 
          class="form-select"
          defaultValue={"Please choose the location"}
          // value={this.state.selected} 
          onChange={handleFormChange}>
            {this.state.places.map((value) => (
              <option value={value.addy} key={value.addy}>
                {value.addy}
              </option>
            ))}
          </select>
          </div>
        </form>

        <div>  
        {Object.keys(this.state.selected).length > 0 ? 
        <div>
        <h4>SURFACE VELOCITY: {this.state.selected[0].velocity} km/h</h4>
        <h4>WATER LEVEL: {this.state.selected[0].level} m</h4>
        <h4>safety: {this.state.selected[0].safety}</h4>
        </div> : 
        <div>

        </div> 
        }

  
      </div>
      </div>)

      } else {
        return (
        <div class="spinner-border  align-items-center text-light" role="status">
          <span class="sr-only"></span>
        </div>
        )
      }
    }


    return (
      <div>
                <div className="App">

        <section className='d-flex justify-content-center ayo'>
          {showStuff()}
          <div class="wave wave1"></div>
          <div class="wave wave2"></div>
          <div class="wave wave3"></div>
          <div class="wave wave4"></div>
        </section>
      </div>
      </div>
    );
  }
}

export default App;
