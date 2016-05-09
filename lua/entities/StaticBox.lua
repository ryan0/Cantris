local StaticBox = {}

function StaticBox.new(pos, size)
    local self = {}
    self.Spatial = {
        position = {0, 0}
    }
    self.Physical = {
        b2BodyDef = {
            position = pos,
            type = "b2_staticBody"
        },
        b2FixtureDef = {
            friction = .3,
            restitution = 0.0,
            b2PolygonShape = {
                setAsBox = size
            }
        }
    }
    return self
end

return StaticBox