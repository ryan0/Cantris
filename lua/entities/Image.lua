local Image = {}

function Image.new(file, scl, layer)
    local self = {}
    self.Renderable = {
        zValue = layer
    }
    self.Graphical = {
        texture = file,
        scale = scl
    }
    self.Spatial = {
        position = {0, 0}
    }
    return self
end

return Image