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
    let originalPosts = this.state.posts;
    let post = { title: 'a', body: 'b' };

    let posts = [post, ...this.state.posts];
    this.setState({ posts });

    try {
      let { data: post } = await axios.post(apiEndpoint, post);
    } catch (e) {
      /* handle error */
      alert('Somethings wrong with updating to api');
      this.setState({ posts: originalPosts });
    }
  };

  handleUpdate = async (post) => {
    let originalPosts = this.state.posts;
    post.title = 'UPDATED';

    let posts = [...this.state.posts];
    let index = posts.indexOf(post);
    posts[index] = { ...post };

    this.setState({ posts });

    try {
      await axios.put(apiEndpoint + '/' + post.id, post);
    } catch (e) {
      /* handle error */
      alert('Somethings wrong with updating to api');
      this.setState({ posts: originalPosts });
    }
  };

  handleDelete = async (post) => {
    let originalPosts = this.state.posts;

    let posts = this.state.posts.filter((p) => p.id !== post.id);
    this.setState({ posts });

    try {
      await axios.delete(apiEndpoint + '/' + post.id);
    } catch (e) {
      /* handle error */
      alert('Somethings wrong with updating to api');
      this.setState({ posts: originalPosts });
    }
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
