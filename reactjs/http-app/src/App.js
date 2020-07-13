import React, { Component } from 'react';
import axios from 'axios';
import './App.css';

const apiEndpoint = 'https://jsonplaceholder.typicode.com/posts';

class App extends Component {
  state = {
    posts: [],
  };

  async componentDidMount() {
    const { data: posts } = await axios.get(apiEndpoint);
    this.setState({ posts });
  }

  handleAdd = async () => {
    let obj = { title: 'a', body: 'b' };
    let { data: post } = await axios.post(apiEndpoint, obj);
    console.log(post);
  };

  handleUpdate = (post) => {
    console.log('Update', post);
  };

  handleDelete = (post) => {
    console.log('Delete', post);
  };

  render() {
    return (
      <div className="m-4">
        <button
          className="btn btn-primary mb-2 pl-4 pr-4"
          onClick={this.handleAdd}
        >
          Add
        </button>
        <table className="table">
          <thead>
            <tr>
              <th>Title</th>
              <th>Update</th>
              <th>Delete</th>
            </tr>
          </thead>
          <tbody>
            {this.state.posts.map((post) => (
              <tr key={post.id}>
                <td>{post.title}</td>
                <td>
                  <button
                    className="btn btn-info btn-sm"
                    onClick={() => this.handleUpdate(post)}
                  >
                    Update
                  </button>
                </td>
                <td>
                  <button
                    className="btn btn-danger btn-sm"
                    onClick={() => this.handleDelete(post)}
                  >
                    Delete
                  </button>
                </td>
              </tr>
            ))}
          </tbody>
        </table>
      </div>
    );
  }
}

export default App;
