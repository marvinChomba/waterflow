import axios from "axios";

import logo from './logo.svg';
import './App.css';
import React , { useState } from "react";


const baseURL = "http://localhost:8080/";

const initialState =  [
    {
    id: 1,
    velocity: "4.56",
    level: "15.52",
    location: "-33.954070,18.475240",
    addy: "21 Alma Rd, Rosebank, Cape Town, 7700, South Africa"
    },
    {
    id: 1,
    velocity: "4.56",
    level: "15.52",
    location: "-33.954070,18.475240",
    addy: "21 Alma Rd, Rosebank, Cape Town, 7700, South Africa"
    },
    {
    id: 2,
    velocity: "12.56",
    level: "16.77",
    location: "-1.259170, 36.798440",
    addy: "PQRX+C9P, School Ln, Nairobi, Kenya"
    },
    {
    id: 2,
    velocity: "12.56",
    level: "16.77",
    location: "-1.259170, 36.798440",
    addy: "PQRX+C9P, School Ln, Nairobi, Kenya"
    },
    {
    id: 3,
    velocity: "2.545",
    level: "6.231",
    location: "-33.9434232,18.4550676",
    addy: "Unnamed Road, Table Mountain (Nature Reserve), Cape Town, South Africa"
    }]
;
function App() {

const [places, setPlaces] = useState(initialState);

const [toDisplay, setToDisplay] = useState(0);
const options = ["Claremont", "Rondebosch", "Observatory"];

const [selected, setSelected] = useState(options[0]);

const submit = (e) => {
    const theOne = places.filter(place => {
      if(place.addy == selected) {
        return place
      }
    })

    setToDisplay(theOne[0]);
    
}




  React.useEffect(() => {
    axios.get(baseURL).then(response => {
      console.log(response)
      
    })
  },[]);

  return (
    <div className="App">

      <section>
      <div class="content">
        <h1>WATERFLOW MONITOR</h1>
        <form>
          <select 
          value={selected} 
          onChange={e => setSelected(e.target.value)}>
            {places.map((value) => (
              <option value={value.addy} key={value.addy}>
                {value.addy}
              </option>
            ))}
          </select>
          <button type="button" onClick={submit}>
            Submit
          </button>
        </form>

        <div>
          <h3>Velocity: {toDisplay.velocity}</h3>
          <h3>Level: {toDisplay.level}</h3>

          <p>Safety: good</p>

        </div>
      </div>
        <div class="wave wave1"></div>
        <div class="wave wave2"></div>
        <div class="wave wave3"></div>
        <div class="wave wave4"></div>
      </section>
    </div>
  );
}

export default App;