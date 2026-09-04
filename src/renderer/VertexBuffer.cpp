#include "VertexBuffer.h"

#include <glad/glad.h>


namespace renderer {

    void configureVertexBuffers(
        unsigned int& vertexArray,
        unsigned int& vertexBuffer,
        size_t vertexSize, const void* vertices,
        unsigned int& indexBuffer,
        size_t indexSize, const void* indices
    ) {
        // VERTEX ARRAY OBJECT
        glGenVertexArrays(1, &vertexArray);
        glBindVertexArray(vertexArray);

        // VERTEX BUFFER
        glGenBuffers(1, &vertexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glBufferData(GL_ARRAY_BUFFER, vertexSize, vertices, GL_STATIC_DRAW);

        // VERTEX ATTRIBUTES DESCRIPTION
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // INDEX BUFFER
        glGenBuffers(1, &indexBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize, indices, GL_STATIC_DRAW);
    }
}
