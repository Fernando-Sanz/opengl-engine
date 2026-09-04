#pragma once


namespace renderer {

    void configureVertexBuffers(
        unsigned int& vertexArray,
        unsigned int& vertexBuffer,
        size_t vertexSize, const void* vertices,
        unsigned int& indexBuffer,
        size_t indexSize, const void* indices);
}
